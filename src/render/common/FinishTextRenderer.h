#pragma once

#include <lib/Object.h>
#include <lib/Array.h>
#include <lib/di/ResolvingFactory.h>
#include <gl/Texture.h>

class FinishTextRenderer : public Object
{
    Texture _finishTexture;
    Array<float, 100> _zCoords;
    float _phase;
    float _width;
    float _height;
    float _radiansStep;
    float _widthStep;
    float _textureStep;
    float _alpha;

public:
    FinishTextRenderer();

    void Init();
    void Render();
    float GetWidth();
    float GetHeight();

private:
    void UpdateZCoords();
};

class FinishTextRendererResolvingFactory : public ResolvingFactory<FinishTextRenderer>
{
public:
    FinishTextRenderer* Make(Resolver& resolver) override;
};
