#pragma once

#include <lib/Object.h>
#include <lib/di/ResolvingFactory.h>
#include <model/Ship.h>
#include <render/common/ShipMeshRenderer.h>

class ShipRenderer : public Object
{
    ShipMeshRenderer& _shipMeshRenderer;

public:
    ShipRenderer(ShipMeshRenderer& shipMeshRenderer);

    void Render(Ship& ship, int textureIndex);

private:
    void SetPosition(Ship& ship);
    void RenderAIMovingDirections(Ship& ship);
    void RenderThrottle(Ship& ship);
};

class ShipRendererResolvingFactory : public ResolvingFactory<ShipRenderer>
{
public:
    ShipRenderer* Make(Resolver& resolver) override;
};
