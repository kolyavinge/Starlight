#pragma once

#include <lib/Object.h>
#include <calc/Vector3.h>
#include <model/Track.h>

enum class Direction { Left, Right };

class TrackBuilder : public Object
{
    inline static const float _moveStep = 0.25f;

    TrackPoints& _insidePoints;
    TrackPoints& _outsidePoints;
    TrackPointInfos& _pointInfos;
    int& _pointsCount;

public:
    Vector3 InsideDirection;
    Vector3 OutsideDirection;

    TrackBuilder(TrackPoints& insidePoints, TrackPoints& outsidePoints, TrackPointInfos& pointInfos, int& pointsCount);

    void InitInsidePosition(float x, float y, float z);
    void InitOutsidePosition(float x, float y, float z);
    void Move(float distance);
    void TurnLeft(float degrees, float radius, Vector3 pivotAxis);
    void TurnRight(float degrees, float radius, Vector3 pivotAxis);
    void ConnectStartFinish();
    void ZeroZ();

private:
    void Turn(Direction direction, float degrees, float radius, Vector3 pivotAxis);
    void GetDirections(Direction direction, float radius, Vector3& pivotAxis, Vector3& pivotPoint);
    void UpdateDirections();
};
