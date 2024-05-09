#include <stddef.h>
#include <lib/Memory.h>
#include <gl/opengl.h>
#include <gl/VBOMeshRenderer.h>

VBOMeshRenderer::VBOMeshRenderer()
{
    _textures = nullptr;
    _vao = 0;
    _buffers[0] = 0;
    _buffers[1] = 0;
    _facesCount = 0;
    _activeTextureIndex = 0;
}

VBOMeshRenderer::~VBOMeshRenderer()
{
    Clear();
}

void VBOMeshRenderer::Init(Mesh& mesh)
{
    _textures = &mesh.Textures;
    MakeBuffers(mesh);
}

void VBOMeshRenderer::Clear()
{
    glBindVertexArray(0);
    glDeleteBuffers(2, _buffers);
    glDeleteVertexArrays(1, &_vao);
}

void VBOMeshRenderer::Render()
{
    glActiveTexture(GL_TEXTURE0);
    glEnable(GL_TEXTURE_2D);
    (*_textures)[_activeTextureIndex].Bind();
    glBindVertexArray(_vao);
    glDrawElements(GL_TRIANGLES, _facesCount, GL_UNSIGNED_INT, nullptr);
    glBindVertexArray(0);
    glDisable(GL_TEXTURE_2D);
}

void VBOMeshRenderer::SetActiveTextureIndex(int textureIndex)
{
    _activeTextureIndex = textureIndex;
}

void VBOMeshRenderer::MakeBuffers(Mesh& mesh)
{
    MeshVertex* vertices = Memory::AllocAndZero<MeshVertex>(mesh.VertexCoords.GetCount());
    MakeVertices(mesh, vertices);

    _facesCount = 3 * mesh.Faces.GetCount();
    unsigned int* faces = Memory::AllocAndZero<unsigned int>(_facesCount);
    MakeFaces(mesh, faces);

    glGenVertexArrays(1, &_vao);
    glBindVertexArray(_vao);

    glGenBuffers(2, _buffers);

    glBindBuffer(GL_ARRAY_BUFFER, _buffers[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(MeshVertex) * mesh.VertexCoords.GetCount(), &vertices[0].Vertex.X, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(MeshVertex), (void*)(offsetof(MeshVertex, Vertex)));
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(MeshVertex), (void*)(offsetof(MeshVertex, Normal)));
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(MeshVertex), (void*)(offsetof(MeshVertex, TextureCoords)));
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _buffers[1]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * _facesCount, faces, GL_STATIC_DRAW);

    glBindVertexArray(0);

    Memory::Release(vertices);
    Memory::Release(faces);
}

void VBOMeshRenderer::MakeVertices(Mesh& mesh, MeshVertex* vertices)
{
    for (int i = 0; i < mesh.VertexCoords.GetCount(); i++)
    {
        vertices[i].Vertex = mesh.VertexCoords[i];
        vertices[i].Normal = mesh.NormalCoords[i];
        vertices[i].TextureCoords = mesh.TextureCoords[i];
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
