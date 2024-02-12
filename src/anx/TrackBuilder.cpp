#include <calc/Vector3.h>
#include <calc/Geometry.h>
#include <model/Track.h>
#include <anx/TrackBuilder.h>

TrackBuilder::TrackBuilder(TrackPoints& insidePoints, TrackPoints& outsidePoints, int& pointsCount) :
    _insidePoints(insidePoints),
    _outsidePoints(outsidePoints),
    _pointsCount(pointsCount)
{
    _pointsCount = 1;
}

void TrackBuilder::InitInsidePosition(float x, float y, float z)
{
    _insidePoints[0].Set(x, y, z);
}

void TrackBuilder::InitOutsidePosition(float x, float y, float z)
{
    _outsidePoints[0].Set(x, y, z);
}

void TrackBuilder::Move(float distance)
{
    Vector3 insideDirection(InsideDirection);
    Vector3 outsideDirection(OutsideDirection);
    insideDirection.SetLength(_moveStep);
    outsideDirection.SetLength(_moveStep);
    for (float fraction = 0.0f; fraction < distance; fraction += _moveStep)
    {
        _insidePoints[_pointsCount] = _insidePoints[_pointsCount - 1];
        _outsidePoints[_pointsCount] = _outsidePoints[_pointsCount - 1];
        _insidePoints[_pointsCount].Add(insideDirection);
        _outsidePoints[_pointsCount].Add(outsideDirection);
        _pointsCount++;
    }
}

void TrackBuilder::TurnLeft(float degrees, float radius, Vector3 pivotAxis)
{
    Turn(Direction::Left, degrees, radius, pivotAxis);
    UpdateDirections();
}

void TrackBuilder::TurnRight(float degrees, float radius, Vector3 pivotAxis)
{
    Turn(Direction::Right, degrees, radius, pivotAxis);
    UpdateDirections();
}

void TrackBuilder::ConnectStartFinish()
{
    Vector3 insideDirection(_insidePoints[0]);
    Vector3 outsideDirection(_outsidePoints[0]);
    insideDirection.Sub(_insidePoints[_pointsCount - 1]);
    outsideDirection.Sub(_outsidePoints[_pointsCount - 1]);
    float insideLength = insideDirection.GetLength();
    float outsideLength = outsideDirection.GetLength();
    float distance;
    if (insideLength > outsideLength)
    {
        distance = insideLength;
        insideDirection.SetLength(_moveStep);
        outsideDirection.SetLength(_moveStep * outsideLength / insideLength);
    }
    else
    {
        distance = outsideLength;
        outsideDirection.SetLength(_moveStep);
        insideDirection.SetLength(_moveStep * insideLength / outsideLength);
    }
    for (float fraction = _moveStep; fraction < distance; fraction += _moveStep)
    {
        _insidePoints[_pointsCount] = _insidePoints[_pointsCount - 1];
        _outsidePoints[_pointsCount] = _outsidePoints[_pointsCount - 1];
        _insidePoints[_pointsCount].Add(insideDirection);
        _outsidePoints[_pointsCount].Add(outsideDirection);
        _pointsCount++;
    }
}

void TrackBuilder::CenterTrack()
{
    float minX = _insidePoints[0].X;
    float maxX = _insidePoints[0].X;
    float minY = _insidePoints[0].Y;
    float maxY = _insidePoints[0].Y;
    for (int i = 1; i < _pointsCount; i++)
    {
        if (_insidePoints[i].X < minX) minX = _insidePoints[i].X;
        if (_insidePoints[i].X > maxX) maxX = _insidePoints[i].X;
        if (_insidePoints[i].Y < minY) minY = _insidePoints[i].Y;
        if (_insidePoints[i].Y > maxY) maxY = _insidePoints[i].Y;
    }

    float widthHalf = (maxX - minX) / 2.0f;
    float heightHalf = (maxY - minY) / 2.0f;
    float deltaX = minX + widthHalf;
    float deltaY = minY + heightHalf;

    for (int i = 0; i < _pointsCount; i++)
    {
        _insidePoints[i].X -= deltaX;
        _outsidePoints[i].X -= deltaX;
        _insidePoints[i].Y -= deltaY;
        _outsidePoints[i].Y -= deltaY;
    }
}

void TrackBuilder::ZeroZ()
{
    for (int i = 0; i < _pointsCount; i++)
    {
        _insidePoints[i].Z = 0.0f;
        _outsidePoints[i].Z = 0.0f;
    }
}

void TrackBuilder::Turn(Direction direction, float degrees, float radius, Vector3 pivotAxis)
{
    Vector3 pivotPoint;
    pivotAxis.Normalize();
    GetDirections(direction, radius, pivotAxis, pivotPoint);
    Vector3 insidePoint(_insidePoints[_pointsCount - 1]);
    Vector3 outsidePoint(_outsidePoints[_pointsCount - 1]);
    float radians = Geometry::DegreesToRadians(degrees);
    float step = Geometry::GetRadiansForDistance(_moveStep, radius);
    for (float fraction = step; fraction < radians; fraction += step)
    {
        _insidePoints[_pointsCount] = Geometry::RotatePoint3d(insidePoint, pivotAxis, pivotPoint, fraction);
        _outsidePoints[_pointsCount] = Geometry::RotatePoint3d(outsidePoint, pivotAxis, pivotPoint, fraction);
        _pointsCount++;
    }
}

void TrackBuilder::GetDirections(Direction direction, float radius, Vector3& pivotAxis, Vector3& pivotPoint)
{
    Vector3 turnDirection;
    bool outsideToRight = _outsidePoints[0].X > _insidePoints[0].X;
    if (direction == Direction::Right && outsideToRight ||
        direction == Direction::Left && !outsideToRight)
    {
        turnDirection.Set(_outsidePoints[_pointsCount - 1]);
        turnDirection.Sub(_insidePoints[_pointsCount - 1]);
        turnDirection.SetLength(radius);
        pivotPoint.Set(turnDirection);
        pivotPoint.Add(_outsidePoints[_pointsCount - 1]);
    }
    else
    {
        turnDirection.Set(_insidePoints[_pointsCount - 1]);
        turnDirection.Sub(_outsidePoints[_pointsCount - 1]);
        turnDirection.SetLength(radius);
        pivotPoint.Set(turnDirection);
        pivotPoint.Add(_insidePoints[_pointsCount - 1]);
    }
    if (direction == Direction::Right)
    {
        pivotAxis.Mul(-1.0f);
    }
    pivotAxis.Normalize();
}

void TrackBuilder::UpdateDirections()
{
    InsideDirection.Set(_insidePoints[_pointsCount - 1]);
    InsideDirection.Sub(_insidePoints[_pointsCount - 2]);
    InsideDirection.Normalize();

    OutsideDirection.Set(_outsidePoints[_pointsCount - 1]);
    OutsideDirection.Sub(_outsidePoints[_pointsCount - 2]);
    OutsideDirection.Normalize();
}
