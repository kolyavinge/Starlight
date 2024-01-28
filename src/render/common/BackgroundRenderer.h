#pragma once

#include <lib/Object.h>
#include <gl/Texture.h>
#include <render/common/BackgroundSphere.h>

class BackgroundRenderer : public Object
{
    const float _textureWidthStep;
    const float _textureHeightStep;
    BackgroundSphere _sphere;
    Texture _backgroundTexture;

public:
    BackgroundRenderer();

    void Init();
    void Render();

private:
    void RenderSphereSegment(int level, int point);
};
