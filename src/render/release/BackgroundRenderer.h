#pragma once

#include <lib/Object.h>
#include <calc/Sphere.h>
#include <gl/Texture.h>

class BackgroundRenderer : public Object
{
    Sphere _sphere;
    Texture _backgroundTexture;
    float _textureWidthStep;
    float _textureHeightStep;

public:
    BackgroundRenderer();

    void Init();
    void Render();

private:
    void RenderSphereSegment(int level, int point);
};
