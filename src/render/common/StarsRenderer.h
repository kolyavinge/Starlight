#pragma once

#include <lib/Object.h>
#include <lib/List.h>
#include <lib/di/ResolvingFactory.h>
#include <anx/RandomSpherePoints.h>

class StarsRenderer : public Object
{
    RandomSpherePoints _stars;
    List<float> _glow;
    List<float> _glowSteps;

public:
    StarsRenderer();

    void Render();

private:
    void InitGlow();
};

class StarsRendererResolvingFactory : public ResolvingFactory<StarsRenderer>
{
public:
    StarsRenderer* Make(Resolver& resolver) override;
};
