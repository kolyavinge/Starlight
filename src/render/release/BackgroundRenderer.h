#pragma once

#include <lib/Object.h>
#include <gl/Texture.h>
#include <render/BackgroundSphere.h>

class BackgroundRenderer : public Object
{
    BackgroundSphere _sphere;
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
