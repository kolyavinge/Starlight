#pragma once

#include <lib/Object.h>
#include <calc/Vector3d.h>
#include <model/Track.h>

enum Direction { Left, Right };

class TrackBuilder : public Object
{
    inline static const float _moveStep = 1.0f;
    inline static const float _turnStep = 0.01f;

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
    void TurnLeft(float degrees, float radius, Vector3d pivotAxis);
    void TurnRight(float degrees, float radius, Vector3d pivotAxis);
    void ConnectStartFinish();

private:
    void Turn(Direction direction, float degrees, float radius, Vector3d& pivotAxis);
    void GetDirections(Direction direction, float radius, Vector3d& pivotAxis, Vector3d& pivotPoint);
    void UpdateDirections();
};
