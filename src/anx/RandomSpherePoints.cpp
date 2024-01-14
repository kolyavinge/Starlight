#include <lib/Random.h>
#include <calc/Vector3.h>
#include <anx/RandomSpherePoints.h>

RandomSpherePoints::RandomSpherePoints(float radius, int pointsCount)
{
    _radius = radius;
    _pointsCount = pointsCount;
    CalculatePoints();
}

float RandomSpherePoints::GetRadius()
{
    return _radius;
}

int RandomSpherePoints::GetPointsCount()
{
    return _pointsCount;
}

Vector3& RandomSpherePoints::GetPoint(int index)
{
    return _points[index];
}

void RandomSpherePoints::CalculatePoints()
{
    Random rand;
    for (int i = 0; i < _pointsCount; i++)
    {
        float x = rand.GetFloatFromZeroToOne() - 0.5f;
        float y = rand.GetFloatFromZeroToOne() - 0.5f;
        float z = rand.GetFloatFromZeroToOne() - 0.5f;
        Vector3 point(x, y, z);
        point.SetLength(_radius);
        _points.Add(point);
    }
}
