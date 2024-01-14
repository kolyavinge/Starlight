#pragma once

#include <lib/Object.h>
#include <lib/List.h>
#include <anx/RandomSpherePoints.h>

class StarsRenderer : Object
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
