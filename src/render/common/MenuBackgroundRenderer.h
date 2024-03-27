#pragma once

#include <lib/Object.h>
#include <lib/di/ResolvingFactory.h>
#include <calc/Vector3.h>
#include <render/common/BackgroundRenderer.h>
#include <render/common/StarsRenderer.h>

class MenuBackgroundRenderer : public Object
{
    BackgroundRenderer& _backgroundRenderer;
    StarsRenderer& _starsRenderer;
    Vector3 _turnVector;
    float _turnDegrees;
    Vector3 _zeroVector;
    Vector3 _forwardVector;

public:
    MenuBackgroundRenderer(
        BackgroundRenderer& backgroundRenderer,
        StarsRenderer& starsRenderer);

    void Init();
    void Render();
};

class MenuBackgroundRendererResolvingFactory : public ResolvingFactory<MenuBackgroundRenderer>
{
public:
    MenuBackgroundRenderer* Make(Resolver& resolver) override;
};
