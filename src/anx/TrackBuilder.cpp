#include <calc/Vector3d.h>
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
    Vector3d insideDirection(InsideDirection);
    Vector3d outsideDirection(OutsideDirection);
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

void TrackBuilder::TurnLeft(float degrees, float radius)
{
    Turn(Direction::Left, degrees, radius);
    UpdateDirections();
}

void TrackBuilder::TurnRight(float degrees, float radius)
{
    Turn(Direction::Right, degrees, radius);
    UpdateDirections();
}

void TrackBuilder::ConnectStartFinish()
{
    Vector3d insideDirection(_insidePoints[0]);
    Vector3d outsideDirection(_outsidePoints[0]);
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

void TrackBuilder::Turn(Direction direction, float degrees, float radius)
{
    Vector3d pivotAxis, pivotPoint;
    GetDirections(direction, radius, pivotAxis, pivotPoint);
    float radians = Geometry::DegreesToRadians(degrees);
    Vector3d insidePoint(_insidePoints[_pointsCount - 1]);
    Vector3d outsidePoint(_outsidePoints[_pointsCount - 1]);
    for (float fraction = _turnStep; fraction < radians; fraction += _turnStep)
    {
        TurnTrackPoint(insidePoint, _insidePoints[_pointsCount], pivotAxis, pivotPoint, fraction);
        TurnTrackPoint(outsidePoint, _outsidePoints[_pointsCount], pivotAxis, pivotPoint, fraction);
        _pointsCount++;
    }
}

void TrackBuilder::TurnTrackPoint(Vector3d from, Vector3d& to, Vector3d& pivotAxis, Vector3d& pivotPoint, float radians)
{
    from.Sub(pivotPoint);
    Vector3d rotated(Geometry::RotatePoint3d(from, pivotAxis, radians));
    to.Set(rotated);
    to.Add(pivotPoint);
}

void TrackBuilder::GetDirections(Direction direction, float radius, Vector3d& pivotAxis, Vector3d& pivotPoint)
{
    Vector3d turnDirection;
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
    Vector3d straightDirection(InsideDirection);
    straightDirection.Add(OutsideDirection);
    pivotAxis.Set(straightDirection);
    pivotAxis.VectorProduct(turnDirection);
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
