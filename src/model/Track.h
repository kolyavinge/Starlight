#pragma once

#include <lib/Object.h>
#include <lib/Array.h>
#include <calc/Vector3.h>

#define TrackMaxPoints 10000
#define TrackMaxMiddlePoints 10

class TrackPoints : public Array<Vector3, TrackMaxPoints> { };

class TrackMiddlePoints : public Array<Array<Vector3, TrackMaxMiddlePoints>, TrackMaxPoints> { };

class Track : public Object
{
    Vector3 _startFinishLine;

public:
    int PointsCount;
    TrackPoints OutsidePoints;
    TrackPoints InsidePoints;
    TrackMiddlePoints MiddlePoints;
    TrackPoints Normals;
    Vector3 StraightDirection;
    int StartFinishLineIndex;

    Track();

    void Init();
    virtual void InternalInit() = 0;
    int GetTrackPointIndexFor(Vector3& point, int startIndex);
    bool IsShipMovingInStraightDirection(Vector3& shipStraightDirection);

private:
    void InitMiddlePoints();
    void InitNormals();
    float GetMinSquaredLengthForTrackPoint(Vector3& point, int trackPointIndex);
    int GetNextTrackPointIndex(int currentIndex);
    int GetPrevTrackPointIndex(int currentIndex);
};
