#pragma once

#include <lib/Object.h>
#include <lib/di/ResolvingFactory.h>
#include <model/Ship.h>
#include <gl/Mesh.h>
#include <gl/VBOMeshRenderer.h>

class ShipMesh : public Object
{
    Mesh _shipMesh;
    VBOMeshRenderer _vboMeshRenderer;

public:
    inline static const int PlayerTexture = 0;
    inline static const int Enemy1Texture = 1;
    inline static const int Enemy2Texture = 2;
    inline static const int Enemy3Texture = 3;
    inline static const int DestroyedTexture = 4;

    void Init();
    void Render(Ship& ship, int textureIndex);
    int GetTexturesCount();

private:
    void SetPosition(Ship& ship);
};

class ShipMeshResolvingFactory : public ResolvingFactory<ShipMesh>
{
public:
    ShipMesh* Make(Resolver& resolver) override;
};
