#include <lib/List.h>
#include <lib/String.h>
#include <lib/Directory.h>
#include <lib/Math.h>
#include <anx/GraphicResources.h>
#include <render/mesh/ExhaustMesh.h>

ExhaustMesh::ExhaustMesh()
{
    MakeRadiusPoints();
    MakeVertices();
    MakeNormals();
    MakeTextureCoords();
    MakeFaces();
    LoadTextures();
}

Mesh& ExhaustMesh::GetMesh()
{
    return _mesh;
}

void ExhaustMesh::MakeRadiusPoints()
{
    const float radianStep = Math::PiDouble / (float)CirclePointsCount;
    const float startRadians = Math::Pi;
    float x, z, sin, cos;
    float radians = startRadians;
    for (int pointIndex = 0; pointIndex < CirclePointsCount; pointIndex++)
    {
        sin = Math::Sin(radians);
        cos = Math::Cos(radians);

        x = FromRadius * cos;
        z = FromRadius * sin;
        FromRadiusPoints[pointIndex] = Vector3(x, 0.0f, z);

        x = ToRadius * cos;
        z = ToRadius * sin;
        ToRadiusPoints[pointIndex] = Vector3(x, -Length, z);

        radians += radianStep;
    }
}

void ExhaustMesh::MakeVertices()
{
    for (int pointIndex = 0; pointIndex < CirclePointsCount; pointIndex++)
    {
        _mesh.VertexCoords.Add(FromRadiusPoints[pointIndex]);
        _mesh.VertexCoords.Add(ToRadiusPoints[pointIndex]);
    }
    _mesh.VertexCoords.Add(FromRadiusPoints[0]);
    _mesh.VertexCoords.Add(ToRadiusPoints[0]);
}

void ExhaustMesh::MakeNormals()
{
    for (int i = 0; i < CirclePointsCount; i++)
    {
        _mesh.NormalCoords.AddNew();
        _mesh.NormalCoords.AddNew();
    }
    _mesh.NormalCoords.AddNew();
    _mesh.NormalCoords.AddNew();
}

void ExhaustMesh::MakeTextureCoords()
{
    const float textureStep = 1.0f / (float)CirclePointsCount;
    float textureY = 0.0f;
    for (int i = 0; i < CirclePointsCount; i++)
    {
        _mesh.TextureCoords.Add(Point2(1.0f, textureY));
        _mesh.TextureCoords.Add(Point2(0.0f, textureY));
        textureY += textureStep;
    }
    _mesh.TextureCoords.Add(Point2(1.0f, 1.0f));
    _mesh.TextureCoords.Add(Point2(0.0f, 1.0f));
}

void ExhaustMesh::MakeFaces()
{
    for (int vertexIndex = 0; vertexIndex < _mesh.VertexCoords.GetCount() - 3; vertexIndex++)
    {
        _mesh.Faces.Add(Face(vertexIndex, vertexIndex + 1, vertexIndex + 2));
        _mesh.Faces.Add(Face(vertexIndex + 1, vertexIndex + 2, vertexIndex + 3));
    }
}

void ExhaustMesh::LoadTextures()
{
    List<String> frameFiles;
    Directory::GetFiles(GraphicResources::GetExhaustFilesPath(), frameFiles);
    _mesh.Textures.PrepareEnoughCapacity(frameFiles.GetCount());
    for (int i = 0; i < frameFiles.GetCount(); i++)
    {
        _mesh.Textures.AddNew().Load(frameFiles[i]);
    }
}

ExhaustMesh* ExhaustMeshResolvingFactory::Make(Resolver&)
{
    return new ExhaustMesh();
}
