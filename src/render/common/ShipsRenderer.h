#pragma once

#include <lib/Object.h>
#include <lib/Collection.h>
#include <lib/di/ResolvingFactory.h>
#include <model/Ship.h>
#include <render/common/ShipRenderer.h>

class ShipsRenderer : public Object
{
    ShipRenderer& _shipRenderer;

public:
    ShipsRenderer(ShipRenderer& shipRenderer);

    void Update();
    void Render(Ship& player, Collection<Ship>& enemies);

private:
    void RenderPlayer(Ship& player);
    void RenderEnemies(Collection<Ship>& enemies);
    void RenderShip(Ship& ship, int defaultTexture);
};

class ShipsRendererResolvingFactory : public ResolvingFactory<ShipsRenderer>
{
public:
    ShipsRenderer* Make(Resolver& resolver) override;
};
