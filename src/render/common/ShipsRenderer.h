#pragma once

#include <lib/Object.h>
#include <lib/IArray.h>
#include <lib/di/ResolvingFactory.h>
#include <model/Ship.h>
#include <render/common/ShipMesh.h>

class ShipsRenderer : public Object
{
    ShipMesh _shipMesh;

public:
    void Init();
    void Render(Ship& player, IArray<Ship>& enemies);

private:
    void RenderPlayer(Ship& player);
    void RenderEnemies(IArray<Ship>& enemies);
    void RenderShip(Ship& ship, int defaultTexture);
};

class ShipsRendererResolvingFactory : public ResolvingFactory<ShipsRenderer>
{
public:
    ShipsRenderer* Make(Resolver& resolver) override;
};
