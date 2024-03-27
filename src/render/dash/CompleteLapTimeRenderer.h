#pragma once

#include <lib/Object.h>
#include <lib/String.h>
#include <lib/di/ResolvingFactory.h>
#include <core/Laps.h>
#include <gl/TextRenderer.h>

class CompleteLapTimeRenderer : public Object
{
    TextRenderer& _textRenderer;
    int _completeLapsCount;
    String _lastLapTime;
    String _lastLapMessageString;
    float _alpha;

public:
    CompleteLapTimeRenderer(TextRenderer& textRenderer);

    void Init();
    void Render(Laps& laps);

private:
    void RenderLapTime();
    void RenderLastLap();
};

class CompleteLapTimeRendererResolvingFactory : public ResolvingFactory<CompleteLapTimeRenderer>
{
public:
    CompleteLapTimeRenderer* Make(Resolver& resolver) override;
};
