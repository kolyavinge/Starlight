#include <render/common/BackgroundSphere.h>

BackgroundSphere::BackgroundSphere() : Sphere(Radius, LevelsCount, LevelPointsCount)
{
}

BackgroundSphere* BackgroundSphereResolvingFactory::Make(Resolver&)
{
    return new BackgroundSphere();
}
