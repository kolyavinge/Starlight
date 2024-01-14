#pragma once

#include <lib/Object.h>
#include <lib/List.h>
#include <calc/Vector3.h>

class RandomSpherePoints : public Object
{
    float _radius;
    int _pointsCount;
    List<Vector3> _points;

public:
    RandomSpherePoints(float radius, int pointsCount);
    float GetRadius();
    int GetPointsCount();
    Vector3& GetPoint(int index);

private:
    void CalculatePoints();
};
