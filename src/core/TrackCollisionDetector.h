#pragma once

#include "lib/Object.h"
#include "calc/SegmentIntersector.h"
#include "model/Ship.h"
#include "model/Track.h"

class TrackCollisionDetector : public Object
{
    SegmentIntersector _segmentIntersector;

public:
    bool DetectCollisions(Ship& ship, Track& track);

private:
    bool DetectCollisions(Vector3d& point, Track& track);
    bool DetectCollisions(Vector3d& from, Vector3d& to, Vector3d& point);
};
