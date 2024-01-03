#pragma once

#include <lib/Object.h>
#include <lib/Array.h>
#include <calc/Vector3d.h>

#define TrackMaxPoints 10000
#define TrackMaxMiddlePoints 10

class TrackPoints : public Array<Vector3d, TrackMaxPoints> { };

class TrackMiddlePoints : public Array<Array<Vector3d, TrackMaxMiddlePoints>, TrackMaxPoints> { };

class Track : public Object
{
    Vector3d _startFinishLine;

public:
    int PointsCount;
    TrackPoints OutsidePoints;
    TrackPoints InsidePoints;
    TrackMiddlePoints MiddlePoints;
    TrackPoints Normals;
    Vector3d StraightDirection;
    int StartFinishLineIndex;

    Track();

    void Init();
    virtual void InternalInit() = 0;
    int GetTrackPointIndexFor(Vector3d& point, int startIndex);
    bool IsShipMovingInStraightDirection(Vector3d& shipStraightDirection);

private:
    void InitMiddlePoints();
    void InitNormals();
    float GetMinSquaredLengthForTrackPoint(Vector3d& point, int trackPointIndex);
    int GetNextTrackPointIndex(int currentIndex);
    int GetPrevTrackPointIndex(int currentIndex);
};
