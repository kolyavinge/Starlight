#pragma once

#include <lib/di/ResolvingFactory.h>
#include <core/Constants.h>
#include <calc/Sphere.h>

class BackgroundSphere : public Sphere
{
public:
    inline static const float Radius = Constants::SceneRadius;
    inline static const int LevelsCount = 20;
    inline static const int LevelPointsCount = 180;

    BackgroundSphere();
};

class BackgroundSphereResolvingFactory : public ResolvingFactory<BackgroundSphere>
{
public:
    BackgroundSphere* Make(Resolver& resolver) override;
};
