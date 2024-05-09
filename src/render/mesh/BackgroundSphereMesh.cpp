#include <lib/Point2.h>
#include <anx/GraphicResources.h>
#include <render/mesh/BackgroundSphereMesh.h>

BackgroundSphereMesh::BackgroundSphereMesh()
{
    MakeVertices();
    LoadTextures();
}

Mesh& BackgroundSphereMesh::GetMesh()
{
    return _mesh;
}

void BackgroundSphereMesh::MakeVertices()
{
    BackgroundSphere sphere;
    const float textureWidthStep = 1.0f / (float)sphere.LevelPointsCount;
    const float textureHeightStep = 0.5f / (float)sphere.LevelsCount;
    for (int level = -sphere.GetLevelsCount(); level < sphere.GetLevelsCount(); level++)
    {
        for (int point = 0; point < sphere.GetLevelPointsCount() - 1; point++)
        {
            MakeSphereSegment(sphere, level, point, textureWidthStep, textureHeightStep);
        }
        MakeSphereSegment(sphere, level, sphere.GetLevelPointsCount() - 1, textureWidthStep, textureHeightStep);
    }
}

void BackgroundSphereMesh::MakeSphereSegment(BackgroundSphere& sphere, int level, int point, float textureWidthStep, float textureHeightStep)
{
    float textureX = textureWidthStep * (float)point;
    float textureXNext = textureX + textureWidthStep;
    float textureY = 0.5f + textureHeightStep * (float)level;
    int nextPoint = point + 1;
    if (nextPoint == sphere.GetLevelPointsCount())
    {
        nextPoint = 0;
        textureXNext = 1.0f;
    }

    const int vertexIndex = _mesh.VertexCoords.GetCount();

    _mesh.TextureCoords.Add(Point2(1.0f - textureX, textureY));
    _mesh.VertexCoords.Add(sphere.GetPoint(level, point));
    _mesh.NormalCoords.AddNew();

    _mesh.TextureCoords.Add(Point2(1.0f - textureX, textureY + textureHeightStep));
    _mesh.VertexCoords.Add(sphere.GetPoint(level + 1, point));
    _mesh.NormalCoords.AddNew();

    _mesh.TextureCoords.Add(Point2(1.0f - textureXNext, textureY + textureHeightStep));
    _mesh.VertexCoords.Add(sphere.GetPoint(level + 1, nextPoint));
    _mesh.NormalCoords.AddNew();

    _mesh.TextureCoords.Add(Point2(1.0f - textureXNext, textureY));
    _mesh.VertexCoords.Add(sphere.GetPoint(level, nextPoint));
    _mesh.NormalCoords.AddNew();

    _mesh.Faces.Add(Face(vertexIndex, vertexIndex + 1, vertexIndex + 2));
    _mesh.Faces.Add(Face(vertexIndex, vertexIndex + 2, vertexIndex + 3));
}

void BackgroundSphereMesh::LoadTextures()
{
    _mesh.Textures.AddNew().Load(GraphicResources::GetBackgroundTextureFilePath());
}

BackgroundSphereMesh* BackgroundSphereMeshResolvingFactory::Make(Resolver&)
{
    return new BackgroundSphereMesh();
}
