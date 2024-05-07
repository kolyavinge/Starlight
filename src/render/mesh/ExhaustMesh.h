#pragma once

#include <lib/Object.h>
#include <lib/Array.h>
#include <lib/di/ResolvingFactory.h>
#include <calc/Vector3.h>
#include <gl/Mesh.h>

class ExhaustMesh : public Object
{
    Mesh _mesh;

public:
    inline static const int CirclePointsCount = 32;
    inline static const float FromRadius = 0.09f;
    inline static const float ToRadius = 0.05f;
    inline static const float Length = 1.5f;

    Array<Vector3, CirclePointsCount> FromRadiusPoints;
    Array<Vector3, CirclePointsCount> ToRadiusPoints;

    ExhaustMesh();

    Mesh& GetMesh();

private:
    void MakeRadiusPoints();
    void MakeVertices();
    void MakeNormals();
    void MakeTextureCoords();
    void MakeFaces();
    void LoadTextures();
};

class ExhaustMeshResolvingFactory : public ResolvingFactory<ExhaustMesh>
{
public:
    ExhaustMesh* Make(Resolver& resolver) override;
};
