#include <lib/List.h>
#include <lib/String.h>
#include <lib/Directory.h>
#include <lib/Math.h>
#include <calc/Vector3.h>
#include <anx/GraphicResources.h>
#include <render/mesh/ExhaustMesh.h>

ExhaustMesh::ExhaustMesh()
{
    const int pointsCount = 32;
    MakeVertices(pointsCount);
    MakeNormals(pointsCount);
    MakeTextureCoords(pointsCount);
    MakeFaces();
    LoadTextures();
}

Mesh& ExhaustMesh::GetMesh()
{
    return _mesh;
}

void ExhaustMesh::MakeVertices(int pointsCount)
{
    const float radianStep = Math::PiDouble / (float)pointsCount;
    const float startRadians = Math::Pi;
    float x, z, sin, cos;

    float radians = startRadians;
    for (int i = 0; i < pointsCount; i++)
    {
        cos = Math::Cos(radians);
        sin = Math::Sin(radians);

        x = FromRadius * cos;
        z = FromRadius * sin;
        _mesh.VertexCoords.Add(Vector3(x, 0.0f, z));

        x = ToRadius * cos;
        z = ToRadius * sin;
        _mesh.VertexCoords.Add(Vector3(x, -Length, z));

        radians += radianStep;
    }

    cos = Math::Cos(startRadians);
    sin = Math::Sin(startRadians);

    x = FromRadius * cos;
    z = FromRadius * sin;
    _mesh.VertexCoords.Add(Vector3(x, 0.0f, z));

    x = ToRadius * cos;
    z = ToRadius * sin;
    _mesh.VertexCoords.Add(Vector3(x, -Length, z));
}

void ExhaustMesh::MakeNormals(int pointsCount)
{
    for (int i = 0; i < pointsCount; i++)
    {
        _mesh.NormalCoords.AddNew();
        _mesh.NormalCoords.AddNew();
    }
    _mesh.NormalCoords.AddNew();
    _mesh.NormalCoords.AddNew();
}

void ExhaustMesh::MakeTextureCoords(int pointsCount)
{
    const float textureStep = 1.0f / (float)pointsCount;
    float textureY = 0.0f;
    for (int i = 0; i < pointsCount; i++)
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
