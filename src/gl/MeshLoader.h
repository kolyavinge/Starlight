#pragma once

#include <assimp/scene.h>
#include <assimp/Importer.hpp>
#include <lib/Object.h>
#include <lib/String.h>
#include <lib/List.h>
#include <lib/Point2.h>
#include <calc/Vector3.h>
#include <gl/Face.h>
#include <gl/Texture.h>

class LoadMeshException : public Exception {};

class MeshLoader : public Object
{
    String _filePath;
    Assimp::Importer _importer;
    const aiScene* _aiScene;
    const aiMesh* _aiMesh;

public:
    MeshLoader(String filePath, unsigned int meshIndex = 0);

    void LoadVertexCoords(List<Vector3>& vertexCoords);
    void LoadNormalCoords(List<Vector3>& normalCoords);
    void LoadTextureCoords(List<Point2>& textureCoords);
    void LoadFaces(List<Face>& faces);
    void LoadFirstDiffuseTexture(Texture& texture);
};
