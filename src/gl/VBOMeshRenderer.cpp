#include <glew/glew.h>
#include <lib/Memory.h>
#include <lib/File.h>
#include <anx/GraphicResources.h>
#include <gl/VBOMeshRenderer.h>

VBOMeshRenderer::VBOMeshRenderer()
{
    _textures = nullptr;
    _vao = 0;
    _buffers[0] = 0;
    _buffers[1] = 0;
    _facesCount = 0;
    _activeTextureIndex = 0;
    _shaderProgram = 0;
}

VBOMeshRenderer::~VBOMeshRenderer()
{
    glBindVertexArray(0);
    glDeleteBuffers(2, _buffers);
    glDeleteVertexArrays(1, &_vao);
}

void VBOMeshRenderer::Init(Mesh& mesh)
{
    _textures = &mesh.Textures;
    MakeBuffers(mesh);
    MakeShaders();
}

void VBOMeshRenderer::Render()
{
    glUseProgram(_shaderProgram);
    glActiveTexture(GL_TEXTURE0);
    glEnable(GL_TEXTURE_2D);
    (*_textures)[_activeTextureIndex].Bind();
    glBindVertexArray(_vao);
    glDrawElements(GL_TRIANGLES, _facesCount, GL_UNSIGNED_INT, nullptr);
    glBindVertexArray(0);
    glDisable(GL_TEXTURE_2D);
    glUseProgram(0);
}

void VBOMeshRenderer::SetActiveTextureIndex(int textureIndex)
{
    _activeTextureIndex = textureIndex;
}

void VBOMeshRenderer::MakeBuffers(Mesh& mesh)
{
    MeshVertex* vertexes = Memory::AllocAndZero<MeshVertex>(mesh.VertexCoords.GetCount());
    MakeVertexes(mesh, vertexes);

    _facesCount = 3 * mesh.Faces.GetCount();
    unsigned int* faces = Memory::AllocAndZero<unsigned int>(_facesCount);
    MakeFaces(mesh, faces);

    glGenVertexArrays(1, &_vao);
    glBindVertexArray(_vao);

    glGenBuffers(2, _buffers);

    glBindBuffer(GL_ARRAY_BUFFER, _buffers[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(MeshVertex) * mesh.VertexCoords.GetCount(), &vertexes[0].Vertex.X, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(MeshVertex), (void*)(offsetof(MeshVertex, Vertex)));
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(MeshVertex), (void*)(offsetof(MeshVertex, Normal)));
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(MeshVertex), (void*)(offsetof(MeshVertex, TextureCoords)));
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _buffers[1]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * _facesCount, faces, GL_STATIC_DRAW);

    glBindVertexArray(0);

    Memory::Release(vertexes);
    Memory::Release(faces);
}

void VBOMeshRenderer::MakeVertexes(Mesh& mesh, MeshVertex* vertexes)
{
    for (int i = 0; i < mesh.VertexCoords.GetCount(); i++)
    {
        vertexes[i].Vertex = mesh.VertexCoords[i];
        vertexes[i].Normal = mesh.NormalCoords[i];
        vertexes[i].TextureCoords = mesh.TextureCoords[i];
    }
}

void VBOMeshRenderer::MakeFaces(Mesh& mesh, unsigned int* faces)
{
    int k = 0;
    for (int i = 0; i < mesh.Faces.GetCount(); i++)
    {
        faces[k++] = mesh.Faces[i].i0;
        faces[k++] = mesh.Faces[i].i1;
        faces[k++] = mesh.Faces[i].i2;
    }
}

void VBOMeshRenderer::MakeShaders()
{
    char vertexSource[512] = {};
    File::ReadAllBytes(GraphicResources::GetSimpleVertexShaderPath().GetWCharBuf(), 512, vertexSource);

    char fragmentSource[512] = {};
    File::ReadAllBytes(GraphicResources::GetSimpleFragmentShaderPath().GetWCharBuf(), 512, fragmentSource);

    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    const GLchar* vs = vertexSource;
    const GLchar* fs = fragmentSource;
    glShaderSource(vertexShader, 1, &vs, 0);
    glShaderSource(fragmentShader, 1, &fs, 0);

    CompileShader(vertexShader);
    CompileShader(fragmentShader);

    _shaderProgram = glCreateProgram();

    glAttachShader(_shaderProgram, vertexShader);
    glAttachShader(_shaderProgram, fragmentShader);
    glLinkProgram(_shaderProgram);
}

void VBOMeshRenderer::CompileShader(unsigned int shaderId)
{
    glCompileShader(shaderId);
    GLint isCompiled = 0;
    glGetShaderiv(shaderId, GL_COMPILE_STATUS, &isCompiled);
    if (isCompiled == GL_FALSE)
    {
        GLint maxLength = 512;
        GLchar errorBuf[512] = {};
        glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &maxLength);
        glGetShaderInfoLog(shaderId, maxLength, &maxLength, errorBuf);
        glDeleteShader(shaderId);
        throw VBOMeshRendererException();
    }
}
