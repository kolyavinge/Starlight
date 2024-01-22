#pragma once

#include <core/GameConstants.h>
#include <calc/Sphere.h>

class BackgroundSphere : public Sphere
{
public:
    inline static const float Radius = GameConstants::SceneRadius;
    inline static const int LevelsCount = 8;
    inline static const int LevelPointsCount = 45;

    BackgroundSphere();
};
