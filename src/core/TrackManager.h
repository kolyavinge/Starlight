#pragma once

#include <lib/Object.h>
#include <lib/di/ResolvingFactory.h>
#include <model/track/RoadTrack1.h>
#include <model/track/RoadTrack2.h>
#include <model/track/RoadTrack3.h>
#include <model/track/RoadTrack4.h>

class TrackManager : public Object
{
public:
    RoadTrack1 Track1;
    RoadTrack2 Track2;
    RoadTrack3 Track3;
    RoadTrack4 Track4;

    TrackManager();
};

class TrackManagerResolvingFactory : public ResolvingFactory<TrackManager>
{
public:
    TrackManager* Make(Resolver& resolver) override;
};
