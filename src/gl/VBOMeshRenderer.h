#pragma once

#include <lib/Exceptions.h>
#include <lib/Object.h>
#include <lib/List.h>
#include <lib/Point2.h>
#include <calc/Vector3.h>
#include <gl/Mesh.h>

class VBOMeshRendererException : public Exception { };

// vertex buffer object
class VBOMeshRenderer : public Object
{
    List<Texture>* _textures;
    unsigned int _vao;
    unsigned int _buffers[2];
    int _facesCount;
    int _activeTextureIndex;
    unsigned int _shaderProgram;

    struct MeshVertex
    {
        Vector3 Vertex;
        Vector3 Normal;
        Point2 TextureCoords;
    };

public:
    VBOMeshRenderer();
    ~VBOMeshRenderer();

    void Init(Mesh& mesh);
    void Render();
    void SetActiveTextureIndex(int textureIndex);

private:
    void MakeBuffers(Mesh& mesh);
    void MakeVertexes(Mesh& mesh, MeshVertex* vertexes);
    void MakeFaces(Mesh& mesh, unsigned int* faces);
    void MakeShaders();
    void CompileShader(unsigned int shaderId);
};
