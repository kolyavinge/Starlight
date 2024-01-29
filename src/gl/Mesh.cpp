#include <gl/opengl.h>
#include <calc/Vector3.h>
#include <calc/VectorCalculator.h>
#include <gl/MeshLoader.h>
#include <gl/Mesh.h>

void Mesh::Load(String filePath, unsigned int meshIndex, unsigned int flags)
{
    if (IsLoaded()) throw ObjectStateException();
    MeshLoader loader(filePath, meshIndex);
    loader.LoadVertexCoords(_vertexCoords);
    loader.LoadNormalCoords(_normalCoords);
    loader.LoadFaces(_faces);
    if ((flags & (int)LoadFlags::NoTexture) == 0)
    {
        loader.LoadTextureCoords(_textureCoords);
        loader.LoadFirstDiffuseTexture(_texture);
    }
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

void Mesh::RenderWired(int faceStep)
{
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < _faces.Count(); i += faceStep)
    {
        Face& face = _faces[i];

        glNormal3f(_normalCoords[face.i0]);
        glVertex3f(_vertexCoords[face.i0]);

        glNormal3f(_normalCoords[face.i1]);
        glVertex3f(_vertexCoords[face.i1]);

        glNormal3f(_normalCoords[face.i2]);
        glVertex3f(_vertexCoords[face.i2]);
    }
    glEnd();
}

void Mesh::MoveToOrigin()
{
    Vector3 min = VectorCalculator::GetMinVector(_vertexCoords);
    for (int i = 0; i < _vertexCoords.Count(); i++)
    {
        _vertexCoords[i].Sub(min);
    }
}

void Mesh::MoveToCenter(int axis)
{
    Vector3 min = VectorCalculator::GetMinVector(_vertexCoords);
    Vector3 max = VectorCalculator::GetMaxVector(_vertexCoords);
    Vector3 lengthHalf = max;
    lengthHalf.Sub(min);
    lengthHalf.Div(2.0f);
    Vector3 delta = min;
    delta.Add(lengthHalf);
    if ((axis & (int)Axis::X) == 0) delta.X = 0.0f;
    if ((axis & (int)Axis::Y) == 0) delta.Y = 0.0f;
    if ((axis & (int)Axis::Z) == 0) delta.Z = 0.0f;
    for (int i = 0; i < _vertexCoords.Count(); i++)
    {
        _vertexCoords[i].Sub(delta);
    }
}

void Mesh::SwapYZ()
{
    VectorCalculator::SwapYZ(_vertexCoords);
    VectorCalculator::SwapYZ(_normalCoords);
}

bool Mesh::IsLoaded()
{
    return _vertexCoords.Count() > 0;
}

void Mesh::GetSize(Size& result)
{
    Vector3 min = VectorCalculator::GetMinVector(_vertexCoords);
    Vector3 max = VectorCalculator::GetMaxVector(_vertexCoords);

    result.MinX = min.X;
    result.MinY = min.Y;
    result.MinZ = min.Z;
    result.MaxX = max.X;
    result.MaxY = max.Y;
    result.MaxZ = max.Z;
    result.XLength = (max.X - min.X);
    result.YLength = (max.Y - min.Y);
    result.ZLength = (max.Z - min.Z);
}
