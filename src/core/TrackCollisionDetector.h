#pragma once

#include <lib/Object.h>
#include <calc/Vector3d.h>
#include <calc/SegmentIntersector.h>
#include <model/Ship.h>
#include <model/Track.h>

class TrackCollisionResult : public Object
{
public:
    Vector3d FromTrackPoint;
    Vector3d ToTrackPoint;
    Vector3d OppositeTrackPoint;
    int FromIndex = 0;
    int ToIndex = 0;
};

class TrackCollisionDetector : public Object
{
    SegmentIntersector _segmentIntersector;

public:
    bool DetectCollisions(Ship& ship, Track& track, TrackCollisionResult& result);

private:
    bool DetectCollisions(Track& track, int& nearTrackPointIndex, Vector3d& point, TrackCollisionResult& result);
    bool DetectCollisions(Track& track, TrackPoints& trackPoints, TrackPoints& oppositeTrackPoints, int& nearTrackPointIndex, Vector3d& point, TrackCollisionResult& result);
    bool DetectCollisions(Vector3d& from, Vector3d to, Vector3d opposite, Vector3d point);
};
