#pragma once

#include <lib/Object.h>
#include <lib/String.h>
#include <lib/di/ResolvingFactory.h>
#include <core/Laps.h>
#include <gl/TextRenderer.h>

class LapsCountRenderer : public Object
{
    TextRenderer& _textRenderer;
    String _lapsCountString;

public:
    LapsCountRenderer(TextRenderer& textRenderer);

    void Render(Laps& laps);
};

class LapsCountRendererResolvingFactory : public ResolvingFactory<LapsCountRenderer>
{
public:
    LapsCountRenderer* Make(Resolver& resolver) override;
};
