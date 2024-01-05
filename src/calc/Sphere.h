#pragma once

#include <lib/Object.h>
#include <lib/List.h>
#include <calc/Vector3d.h>

class Sphere : public Object
{
    float _radius;
    int _levelsCount;
    int _levelPointsCount;
    List<Vector3d> _equator;
    List<Vector3d> _up;
    List<Vector3d> _down;

public:
    Sphere(float radius, int levelsCount, int levelPointsCount);

    int GetLevelsCount();
    int GetLevelPointsCount();
    Vector3d& GetPoint(int levelIndex, int pointIndex);

private:
    void CalculatePoints();
};
