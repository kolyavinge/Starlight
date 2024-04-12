#pragma once

#include <lib/Object.h>
#include <lib/di/ResolvingFactory.h>
#include <gl/Mesh.h>
#include <gl/VBOMeshRenderer.h>

class ShipMeshRenderer : public Object
{
    Mesh _shipMesh;
    VBOMeshRenderer _vboMeshRenderer;

public:
    inline static const int PlayerTexture = 0;
    inline static const int Enemy1Texture = 1;
    inline static const int Enemy2Texture = 2;
    inline static const int Enemy3Texture = 3;
    inline static const int DestroyedTexture = 4;

    ShipMeshRenderer();

    void Render(int textureIndex);
    int GetTexturesCount();
};

class ShipMeshRendererResolvingFactory : public ResolvingFactory<ShipMeshRenderer>
{
public:
    ShipMeshRenderer* Make(Resolver& resolver) override;
};
