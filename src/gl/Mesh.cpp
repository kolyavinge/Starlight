#include <gl/opengl.h>
#include <calc/Vector3.h>
#include <calc/VectorCalculator.h>
#include <gl/MeshLoader.h>
#include <gl/Mesh.h>

Mesh::Mesh()
{
    _xLength = 0.0f;
    _yLength = 0.0f;
    _zLength = 0.0f;
}

void Mesh::Load(String filePath, unsigned int meshIndex)
{
    if (IsLoaded()) throw ObjectStateException();
    MeshLoader loader(filePath, meshIndex);
    loader.LoadVertexCoords(_vertexCoords);
    loader.LoadNormalCoords(_normalCoords);
    loader.LoadTextureCoords(_textureCoords);
    loader.LoadFaces(_faces);
    loader.LoadFirstDiffuseTexture(_texture);
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

bool Mesh::IsLoaded()
{
    return _vertexCoords.Count() > 0;
}
