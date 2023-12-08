#pragma once

#include "lib/Object.h"
#include "calc/SegmentIntersector.h"
#include "model/Ship.h"
#include "model/Track.h"

class TrackCollisionResult : public Object
{
public:
    Vector3d From;
    Vector3d To;
    int FromIndex;
    int ToIndex;
};

class TrackCollisionDetector : public Object
{
    SegmentIntersector _segmentIntersector;

public:
    bool DetectCollisions(Ship& ship, Track& track, TrackCollisionResult& result);

private:
    bool DetectCollisions(Vector3d& point, Track& track, TrackCollisionResult& result);
    bool DetectCollisions(Vector3d& point, TrackPoints& trackPoints, int pointsCount, TrackCollisionResult& result);
    bool DetectCollisions(Vector3d& from, Vector3d& to, Vector3d& point);
};
