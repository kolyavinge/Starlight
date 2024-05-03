#pragma once

#include <lib/Object.h>
#include <lib/di/ResolvingFactory.h>
#include <gl/Mesh.h>

class ExhaustMesh : public Object
{
    Mesh _mesh;

public:
    inline static const float FromRadius = 0.09f;
    inline static const float ToRadius = 0.065f;
    inline static const float Length = 1.0f;

    ExhaustMesh();

    Mesh& GetMesh();

private:
    void MakeVertices(int pointsCount);
    void MakeNormals(int pointsCount);
    void MakeTextureCoords(int pointsCount);
    void MakeFaces();
    void LoadTextures();
};

class ExhaustMeshResolvingFactory : public ResolvingFactory<ExhaustMesh>
{
public:
    ExhaustMesh* Make(Resolver& resolver) override;
};
