#pragma once

#include <calc/Sphere.h>

class BackgroundSphere : public Sphere
{
public:
    inline static const float Radius = 1000.0f;
    inline static const int LevelsCount = 8;
    inline static const int LevelPointsCount = 45;

    BackgroundSphere();
};
