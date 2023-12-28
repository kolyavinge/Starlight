#pragma once

#include <lib/Object.h>
#include <lib/Array.h>
#include <calc/Vector3d.h>

#define TrackMaxPoints 10000
#define TrackMaxMiddlePoints 1000

class TrackPoints : public Array<Vector3d, TrackMaxPoints> { };

class TrackMiddlePoints : public Array<Array<Vector3d, TrackMaxMiddlePoints>, TrackMaxPoints> { };

class Track : public Object
{
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
    int GetNearestTrackPointIndex(TrackPoints& trackPoints, Vector3d& point);

private:
    void InitMiddlePoints();
    void InitNormals();
};
