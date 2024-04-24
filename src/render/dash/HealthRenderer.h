#pragma once

#include <lib/Object.h>
#include <lib/String.h>
#include <lib/di/ResolvingFactory.h>
#include <model/Ship.h>
#include <gl/TextRenderer.h>

class HealthRenderer : public Object
{
    TextRenderer& _textRenderer;
    String _healthValueText;

public:
    HealthRenderer(TextRenderer& textRenderer);

    void Render(Ship& player);
};

class HealthRendererResolvingFactory : public ResolvingFactory<HealthRenderer>
{
public:
    HealthRenderer* Make(Resolver& resolver) override;
};
