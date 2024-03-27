#pragma once

#include <lib/Object.h>
#include <lib/di/ResolvingFactory.h>
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

class BackgroundRendererResolvingFactory : public ResolvingFactory<BackgroundRenderer>
{
public:
    BackgroundRenderer* Make(Resolver& resolver) override;
};
