#pragma once

#include <lib/Object.h>
#include <calc/Vector3.h>
#include <model/Ship.h>
#include <model/Track.h>
#include <core/cm/TrackCollisionResult.h>

class TrackCollisionDetector : public Object
{
public:
    TrackCollisionResult Result;

    bool DetectCollisions(Ship& ship, Track& track);
    bool DetectCollisions(Track& track, int trackPointIndex, Vector3& point);

private:
    bool DetectCollisions(TrackPoints& trackPoints, TrackPoints& oppositeTrackPoints, int fromTrackPointIndex, int toTrackPointIndex, Vector3& point);
};
