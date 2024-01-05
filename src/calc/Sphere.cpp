#include <lib/Math.h>
#include <calc/Sphere.h>

Sphere::Sphere(float radius, int levelsCount, int levelPointsCount) :
    _equator(levelPointsCount),
    _up(levelsCount* levelPointsCount),
    _down(levelsCount* levelPointsCount)
{
    _radius = radius;
    _levelsCount = levelsCount;
    _levelPointsCount = levelPointsCount;
    CalculatePoints();
}

int Sphere::GetLevelsCount()
{
    return _levelsCount;
}

int Sphere::GetLevelPointsCount()
{
    return _levelPointsCount;
}

Vector3d& Sphere::GetPoint(int levelIndex, int pointIndex)
{
    if (levelIndex == 0)
    {
        return _equator[pointIndex];
    }
    else if (levelIndex > 0)
    {
        return _up[(levelIndex - 1) * _levelPointsCount + pointIndex];
    }
    else
    {
        return _down[((-levelIndex) - 1) * _levelPointsCount + pointIndex];
    }
}

void Sphere::CalculatePoints()
{
    const float levelRadiansStep = Math::PiHalf / (float)_levelsCount;
    const float pointRadiansStep = Math::PiDouble / (float)_levelPointsCount;
    for (int point = 0; point < _levelPointsCount; point++)
    {
        float pointRadians = pointRadiansStep * (float)point;
        float x = _radius * Math::Cos(pointRadians);
        float y = _radius * Math::Sin(pointRadians);
        _equator.Add(Vector3d(x, y, 0.0f));
    }
    for (int level = 1; level <= _levelsCount; level++)
    {
        float levelRadians = levelRadiansStep * (float)level;
        float levelRadius = _radius * Math::Cos(levelRadians);
        float z = _radius * Math::Sin(levelRadians);
        for (int point = 0; point < _levelPointsCount; point++)
        {
            float pointRadians = pointRadiansStep * (float)point;
            float x = levelRadius * Math::Cos(pointRadians);
            float y = levelRadius * Math::Sin(pointRadians);
            _up.Add(Vector3d(x, y, z));
            _down.Add(Vector3d(x, y, -z));
        }
    }
}
