#pragma once

#include <lib/Object.h>
#include <lib/String.h>
#include <lib/di/ResolvingFactory.h>
#include <core/Laps.h>
#include <gl/TextRenderer.h>

class CompleteLapsTimeListRenderer : public Object
{
    const float _scale = 0.8f;
    TextRenderer& _textRenderer;
    String _lapTimeString;

public:
    CompleteLapsTimeListRenderer(TextRenderer& textRenderer);

    void Render(Laps& laps);
};

class CompleteLapsTimeListRendererResolvingFactory : public ResolvingFactory<CompleteLapsTimeListRenderer>
{
public:
    CompleteLapsTimeListRenderer* Make(Resolver& resolver) override;
};
