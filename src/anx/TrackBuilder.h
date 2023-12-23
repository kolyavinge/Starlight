#pragma once

#include <lib/Object.h>
#include <calc/Vector3d.h>
#include <model/Track.h>

enum Direction { Left, Right };

class TrackBuilder : public Object
{
    TrackPoints& _insidePoints;
    TrackPoints& _outsidePoints;
    int& _pointsCount;

public:
    Vector3d InsideDirection;
    Vector3d OutsideDirection;

    TrackBuilder(TrackPoints& insidePoints, TrackPoints& outsidePoints, int& pointsCount);

    void InitInsidePosition(float x, float y, float z);
    void InitOutsidePosition(float x, float y, float z);
    void Move(float distance);
    void TurnLeft(float degrees, float radius);
    void TurnRight(float degrees, float radius);

private:
    void Turn(Direction direction, float degrees, float radius);
    void TurnTrackPoint(Vector3d from, Vector3d& to, Vector3d& pivotAxis, Vector3d& pivotPoint, float radians);
    void GetDirections(Direction direction, float radius, Vector3d& pivotAxis, Vector3d& pivotPoint);
    void UpdateDirections();
};
