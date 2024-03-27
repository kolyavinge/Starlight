#pragma once

#include <lib/Object.h>
#include <lib/di/ResolvingFactory.h>
#include <gl/TexturedRect.h>

class GoRenderer : public Object
{
    TexturedRect* _goItem;
    float _alpha;

public:
    GoRenderer();

    void Init(TexturedRect& goItem);
    void Reset();
    void Render();
};

class GoRendererResolvingFactory : public ResolvingFactory<GoRenderer>
{
public:
    GoRenderer* Make(Resolver& resolver) override;
};
