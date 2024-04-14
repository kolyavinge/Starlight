#pragma once

#include <lib/Object.h>
#include <lib/di/ResolvingFactory.h>
#include <gl/Mesh.h>

class ShipMesh : public Object
{
    Mesh _mesh;

public:
    inline static const int PlayerTexture = 0;
    inline static const int Enemy1Texture = 1;
    inline static const int Enemy2Texture = 2;
    inline static const int Enemy3Texture = 3;
    inline static const int DestroyedTexture = 4;

    ShipMesh();

    Mesh& GetMesh();
};

class ShipMeshResolvingFactory : public ResolvingFactory<ShipMesh>
{
public:
    ShipMesh* Make(Resolver& resolver) override;
};
