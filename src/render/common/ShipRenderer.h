#pragma once

#include <lib/Object.h>
#include <lib/di/ResolvingFactory.h>
#include <model/Ship.h>
#include <render/common/ShipMesh.h>

class ShipRenderer : public Object
{
    ShipMesh& _shipMesh;

public:
    ShipRenderer(ShipMesh& shipMesh);

    void Init();
    void Render(Ship& ship, int textureIndex);
};

class ShipRendererResolvingFactory : public ResolvingFactory<ShipRenderer>
{
public:
    ShipRenderer* Make(Resolver& resolver) override;
};
