#pragma once

#include <lib/Object.h>
#include <lib/di/ResolvingFactory.h>
#include <calc/Vector3.h>
#include <model/Ship.h>
#include <model/Track.h>

class TrackCollisionResult : public Object
{
public:
    Vector3 FromTrackPoint;
    Vector3 ToTrackPoint;
    Vector3 OppositeTrackPoint;
    int FromIndex;
    int ToIndex;

    TrackCollisionResult();

    void Init();
};

class TrackCollisionDetector : public Object
{
public:
    TrackCollisionResult Result;

    bool DetectCollisions(Ship& ship, Track& track);
    bool DetectCollisions(Track& track, int trackPointIndex, Vector3& point);

private:
    bool DetectCollisions(TrackPoints& trackPoints, TrackPoints& oppositeTrackPoints, int fromTrackPointIndex, int toTrackPointIndex, Vector3& point);
};

class TrackCollisionDetectorResolvingFactory : public ResolvingFactory<TrackCollisionDetector>
{
public:
    TrackCollisionDetector* Make(Resolver& resolver) override;
};
