#pragma once

#include <lib/Object.h>
#include <calc/Vector3d.h>
#include <calc/SegmentIntersector.h>
#include <model/Ship.h>
#include <model/Track.h>
#include <core/TrackCollisionResult.h>

class TrackCollisionDetector : public Object
{
    SegmentIntersector _segmentIntersector;

public:
    TrackCollisionResult Result;

    bool DetectCollisions(Ship& ship, Track& track);

private:
    bool DetectCollisions(Track& track, int lastNearTrackPointIndex, Vector3d& point);
    bool DetectCollisions(Track& track, TrackPoints& trackPoints, TrackPoints& oppositeTrackPoints, int lastNearTrackPointIndex, Vector3d& point);
    bool DetectCollisions(Vector3d& from, Vector3d to, Vector3d opposite, Vector3d point);
};
