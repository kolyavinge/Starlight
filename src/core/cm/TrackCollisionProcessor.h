#pragma once

#include <lib/Object.h>
#include <lib/di/ResolvingFactory.h>
#include <model/Ship.h>
#include <model/Track.h>
#include <core/cm/TrackCollisionDetector.h>

class TrackCollisionProcessor : public Object
{
    TrackCollisionDetector _trackCollisionDetector;

public:
    bool ProcessTrackCollisions(Ship& ship, Track& track);
};

class TrackCollisionProcessorResolvingFactory : public ResolvingFactory<TrackCollisionProcessor>
{
public:
    TrackCollisionProcessor* Make(Resolver& resolver) override;
};
