#pragma once

#include <lib/Object.h>
#include <lib/List.h>
#include <calc/Vector3.h>

class Sphere : public Object
{
    float _radius;
    int _levelsCount;
    int _levelPointsCount;
    List<Vector3> _equator;
    List<Vector3> _up;
    List<Vector3> _down;

public:
    Sphere(float radius, int levelsCount, int levelPointsCount);

    int GetLevelsCount();
    int GetLevelPointsCount();
    Vector3& GetPoint(int levelIndex, int pointIndex);

private:
    void CalculatePoints();
};
