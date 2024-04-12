#include <assimp/postprocess.h>
#include <lib/Assert.h>
#include <lib/Path.h>
#include <gl/MeshLoader.h>

MeshLoader::MeshLoader(String filePath, unsigned int meshIndex)
{
    _filePath = filePath;
    _aiScene = _importer.ReadFile(filePath.GetCharBuf(), aiProcess_Triangulate);
    if (meshIndex >= _aiScene->mNumMeshes) throw LoadMeshException();
    _aiMesh = _aiScene->mMeshes[meshIndex];
    if (_aiMesh->mNumVertices == 0) throw LoadMeshException();
}

void MeshLoader::LoadVertexCoords(List<Vector3>& vertexCoords)
{
    vertexCoords.PrepareEnoughCapacity(_aiMesh->mNumVertices);
    for (unsigned int i = 0; i < _aiMesh->mNumVertices; i++)
    {
        aiVector3D& pos = _aiMesh->mVertices[i];
        vertexCoords.Add(Vector3(pos.x, pos.y, pos.z));
    }
}

void MeshLoader::LoadNormalCoords(List<Vector3>& normalCoords)
{
    normalCoords.PrepareEnoughCapacity(_aiMesh->mNumVertices);
    for (unsigned int i = 0; i < _aiMesh->mNumVertices; i++)
    {
        aiVector3D& normal = _aiMesh->mNormals[i];
        normalCoords.Add(Vector3(normal.x, normal.y, normal.z));
    }
    for (int i = 0; i < normalCoords.GetCount(); i++)
    {
        normalCoords[i].Normalize();
    }
}

void MeshLoader::LoadTextureCoords(List<Point2>& textureCoords)
{
    if (_aiMesh->HasTextureCoords(0))
    {
        textureCoords.PrepareEnoughCapacity(_aiMesh->mNumVertices);
        for (unsigned int i = 0; i < _aiMesh->mNumVertices; i++)
        {
            textureCoords.Add(Point2(_aiMesh->mTextureCoords[0][i].x, _aiMesh->mTextureCoords[0][i].y));
        }
    }
}

void MeshLoader::LoadFaces(List<Face>& faces)
{
    faces.PrepareEnoughCapacity(_aiMesh->mNumFaces);
    for (unsigned int i = 0; i < _aiMesh->mNumFaces; i++)
    {
        aiFace& face = _aiMesh->mFaces[i];
        Assert::True(face.mNumIndices == 3);
        faces.Add(Face(face.mIndices[0], face.mIndices[1], face.mIndices[2]));
    }
}

void MeshLoader::LoadDiffuseTextures(List<Texture>& textures)
{
    String fileDir = Path::GetDirectoryPath(_filePath);
    for (unsigned int i = 0; i < _aiScene->mNumMaterials; i++)
    {
        aiMaterial* material = _aiScene->mMaterials[i];
        if (material->GetTextureCount(aiTextureType_DIFFUSE) > 0)
        {
            aiString path;
            if (material->GetTexture(aiTextureType_DIFFUSE, 0, &path) == AI_SUCCESS)
            {
                String textureFileName(path.data);
                String textureFilePath(fileDir);
                textureFilePath.Append(L'\\');
                textureFilePath.Append(textureFileName);
                textures.AddNew();
                textures[textures.GetCount() - 1].Load(textureFilePath);
            }
        }
    }
}
