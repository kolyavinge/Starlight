#include <gl/opengl.h>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <lib/Assert.h>
#include <lib/Path.h>
#include <calc/Vector3.h>
#include <calc/VectorCalculator.h>
#include <gl/Mesh.h>

Mesh::Mesh()
{
    _xLength = 0.0f;
    _yLength = 0.0f;
    _zLength = 0.0f;
}

void Mesh::Load(String filePath, unsigned int meshIndex)
{
    if (IsAlreadyLoaded()) throw LoadMeshException();
    Assimp::Importer importer;
    const aiScene* aiScene = importer.ReadFile(filePath.GetCharBuf(), aiProcess_Triangulate);
    if (meshIndex >= aiScene->mNumMeshes) throw LoadMeshException();
    InitMesh(aiScene->mMeshes[meshIndex]);
    InitMaterials(aiScene, filePath);
    MoveToOrigin();
    CalculateXYZLength();
}

void Mesh::Render()
{
    glEnable(GL_TEXTURE_2D);
    _texture.Bind();
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < _faces.Count(); i++)
    {
        Face& face = _faces[i];

        glNormal3f(_normalCoords[face.i0]);
        glTexCoord2f(_textureCoords[face.i0]);
        glVertex3f(_vertexCoords[face.i0]);

        glNormal3f(_normalCoords[face.i1]);
        glTexCoord2f(_textureCoords[face.i1]);
        glVertex3f(_vertexCoords[face.i1]);

        glNormal3f(_normalCoords[face.i2]);
        glTexCoord2f(_textureCoords[face.i2]);
        glVertex3f(_vertexCoords[face.i2]);
    }
    glEnd();
    glDisable(GL_TEXTURE_2D);
}

float Mesh::GetXLength()
{
    return _xLength;
}

float Mesh::GetYLength()
{
    return _yLength;
}

float Mesh::GetZLength()
{
    return _zLength;
}

void Mesh::MoveToCenter(int axis)
{
    Vector3 delta;
    if (axis & Axis::X) delta.X = _xLength / 2.0f;
    if (axis & Axis::Y) delta.Y = _yLength / 2.0f;
    if (axis & Axis::Z) delta.Z = _zLength / 2.0f;
    for (int i = 0; i < _vertexCoords.Count(); i++)
    {
        _vertexCoords[i].Sub(delta);
    }
}

void Mesh::SwapYZ()
{
    VectorCalculator::SwapYZ(_vertexCoords);
    VectorCalculator::SwapYZ(_normalCoords);
    MoveToOrigin();
    CalculateXYZLength();
}

void Mesh::InitMesh(aiMesh* aiMesh)
{
    if (aiMesh->mNumVertices == 0) throw LoadMeshException();

    _vertexCoords.PrepareEnoughCapacity(aiMesh->mNumVertices);
    _normalCoords.PrepareEnoughCapacity(aiMesh->mNumVertices);
    _textureCoords.PrepareEnoughCapacity(aiMesh->mNumVertices);
    _faces.PrepareEnoughCapacity(aiMesh->mNumFaces);

    for (unsigned int i = 0; i < aiMesh->mNumVertices; i++)
    {
        aiVector3D& pos = aiMesh->mVertices[i];
        _vertexCoords.Add(Vector3(pos.x, pos.y, pos.z));

        aiVector3D& normal = aiMesh->mNormals[i];
        _normalCoords.Add(Vector3(normal.x, normal.y, normal.z));

        if (aiMesh->HasTextureCoords(0))
        {
            _textureCoords.Add(Point2(aiMesh->mTextureCoords[0][i].x, aiMesh->mTextureCoords[0][i].y));
        }
    }

    for (unsigned int i = 0; i < aiMesh->mNumFaces; i++)
    {
        aiFace& face = aiMesh->mFaces[i];
        Assert::True(face.mNumIndices == 3);
        _faces.Add(Face{ face.mIndices[0], face.mIndices[1], face.mIndices[2] });
    }
}

void Mesh::InitMaterials(const aiScene* aiScene, String filePath)
{
    String fileDir = Path::GetDirectoryPath(filePath);
    for (unsigned int i = 0; i < aiScene->mNumMaterials; i++)
    {
        aiMaterial* material = aiScene->mMaterials[i];
        if (material->GetTextureCount(aiTextureType_DIFFUSE) > 0)
        {
            aiString path;
            if (material->GetTexture(aiTextureType_DIFFUSE, 0, &path) == AI_SUCCESS)
            {
                String textureFileName(path.data);
                String textureFilePath(fileDir);
                textureFilePath.Append(L'\\');
                textureFilePath.Append(textureFileName);
                _texture.Load(textureFilePath);
                return;
            }
        }
    }

    throw LoadMeshException();
}

void Mesh::MoveToOrigin()
{
    Vector3 min = VectorCalculator::GetMinVector(_vertexCoords);
    for (int i = 0; i < _vertexCoords.Count(); i++)
    {
        _vertexCoords[i].Sub(min);
    }
}

void Mesh::CalculateXYZLength()
{
    Vector3 max = VectorCalculator::GetMaxVector(_vertexCoords);
    _xLength = max.X;
    _yLength = max.Y;
    _zLength = max.Z;
}

bool Mesh::IsAlreadyLoaded()
{
    return _vertexCoords.Count() > 0;
}
