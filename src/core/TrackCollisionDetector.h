#pragma once

#include <lib/Object.h>
#include <calc/Vector3.h>
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
    bool DetectCollisions(Track& track, int trackPointIndex, Vector3& point);
    bool DetectCollisions(Track& track, TrackPoints& trackPoints, TrackPoints& oppositeTrackPoints, int trackPointIndex, Vector3& point);
    bool DetectCollisions(Vector3& from, Vector3 to, Vector3 opposite, Vector3 point);
};
