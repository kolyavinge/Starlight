#include <calc/Vector3.h>
#include <calc/VectorCalculator.h>
#include <gl/MeshLoader.h>
#include <gl/Mesh.h>

Mesh::Mesh() :
    Textures(4)
{
}

void Mesh::Load(String filePath, unsigned int meshIndex, unsigned int flags)
{
    if (IsLoaded()) throw ObjectStateException();
    MeshLoader loader(filePath, meshIndex);
    loader.LoadVertexCoords(VertexCoords);
    loader.LoadNormalCoords(NormalCoords);
    loader.LoadFaces(Faces);
    if ((flags & (int)LoadFlags::NoTexture) == 0)
    {
        loader.LoadTextureCoords(TextureCoords);
        loader.LoadDiffuseTextures(Textures);
    }
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
    result.XLength = (max.X - min.X);
    result.YLength = (max.Y - min.Y);
    result.ZLength = (max.Z - min.Z);
}
