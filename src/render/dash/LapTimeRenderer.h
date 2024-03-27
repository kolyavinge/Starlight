#pragma once

#include <lib/Object.h>
#include <lib/String.h>
#include <lib/di/ResolvingFactory.h>
#include <core/Laps.h>
#include <gl/TextRenderer.h>

class LapTimeRenderer : public Object
{
    TextRenderer& _textRenderer;
    String _lapTimeString;

public:
    LapTimeRenderer(TextRenderer& textRenderer);

    void Render(Laps& laps);
};

class LapTimeRendererResolvingFactory : public ResolvingFactory<LapTimeRenderer>
{
public:
    LapTimeRenderer* Make(Resolver& resolver) override;
};
