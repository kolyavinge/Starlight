#pragma once

#include <lib/Object.h>
#include <lib/String.h>
#include <lib/di/ResolvingFactory.h>
#include <model/Ship.h>
#include <gl/TextRenderer.h>

class PlayerShipHealthRenderer : public Object
{
    TextRenderer& _textRenderer;
    String _healthValueText;

public:
    PlayerShipHealthRenderer(TextRenderer& textRenderer);

    void Render(Ship& player);
};

class PlayerShipHealthRendererResolvingFactory : public ResolvingFactory<PlayerShipHealthRenderer>
{
public:
    PlayerShipHealthRenderer* Make(Resolver& resolver) override;
};
