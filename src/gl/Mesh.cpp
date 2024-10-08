#include <lib/Utils.h>
#include <calc/Vector3.h>
#include <calc/VectorCalculator.h>
#include <gl/MeshLoader.h>
#include <gl/Mesh.h>

Mesh::Mesh() :
    Textures(4)
{
}

void Mesh::Load(String filePath, unsigned int meshIndex)
{
    if (IsLoaded()) throw ObjectStateException();
    MeshLoader loader(filePath, meshIndex);
    loader.LoadVertexCoords(VertexCoords);
    loader.LoadNormalCoords(NormalCoords);
    loader.LoadFaces(Faces);
    loader.LoadTextureCoords(TextureCoords);
    loader.LoadDiffuseTextures(Textures);
}

void Mesh::Clear()
{
    VertexCoords.Clear();
    NormalCoords.Clear();
    TextureCoords.Clear();
    Faces.Clear();
    for (int i = 0; i < Textures.GetCount(); i++)
    {
        Textures[i].Clear();
    }
    Textures.Clear();
}

void Mesh::MoveToOrigin()
{
    Vector3 min = VectorCalculator::GetMinVector(VertexCoords);
    for (int i = 0; i < VertexCoords.GetCount(); i++)
    {
        VertexCoords[i].Sub(min);
    }
}

void Mesh::MoveToCenter(int axis)
{
    Vector3 min = VectorCalculator::GetMinVector(VertexCoords);
    Vector3 max = VectorCalculator::GetMaxVector(VertexCoords);
    Vector3 lengthHalf = max;
    lengthHalf.Sub(min);
    lengthHalf.Div(2.0f);
    Vector3 delta = min;
    delta.Add(lengthHalf);
    if ((axis & (int)Axis::X) == 0) delta.X = 0.0f;
    if ((axis & (int)Axis::Y) == 0) delta.Y = 0.0f;
    if ((axis & (int)Axis::Z) == 0) delta.Z = 0.0f;
    for (int i = 0; i < VertexCoords.GetCount(); i++)
    {
        VertexCoords[i].Sub(delta);
    }
}

void Mesh::SwapYZ()
{
    VectorCalculator::SwapYZ(VertexCoords);
    VectorCalculator::SwapYZ(NormalCoords);
}

void Mesh::SetScale(float x, float y, float z)
{
    for (int i = 0; i < VertexCoords.GetCount(); i++)
    {
        Vector3& v = VertexCoords[i];
        v.X *= x;
        v.Y *= y;
        v.Z *= z;
    }
}

void Mesh::InvertFacing()
{
    for (int i = 0; i < Faces.GetCount(); i++)
    {
        Utils::Swap(Faces[i].i0, Faces[i].i2);
    }
}

bool Mesh::IsLoaded()
{
    return VertexCoords.GetCount() > 0;
}

void Mesh::GetSize(Size& result)
{
    Vector3 min = VectorCalculator::GetMinVector(VertexCoords);
    Vector3 max = VectorCalculator::GetMaxVector(VertexCoords);

    result.MinX = min.X;
    result.MinY = min.Y;
    result.MinZ = min.Z;
    result.MaxX = max.X;
    result.MaxY = max.Y;
    result.MaxZ = max.Z;
    result.XLength = max.X - min.X;
    result.YLength = max.Y - min.Y;
    result.ZLength = max.Z - min.Z;
}
