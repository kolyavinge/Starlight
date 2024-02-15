#pragma once

#include <lib/Object.h>
#include <lib/Array.h>
#include <gl/Texture.h>

class FinishRenderer : public Object
{
    Texture _finishTexture;
    Array<float, 100> _zCoords;
    float _phase;
    float _width;
    float _height;
    float _radiansStep;
    float _widthStep;
    float _textureStep;

public:
    FinishRenderer();

    void Init();
    void Render();
    float GetWidth();
    float GetHeight();

private:
    void UpdateZCoords();
};
