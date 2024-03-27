#pragma once

#include <lib/Object.h>
#include <lib/di/ResolvingFactory.h>
#include <calc/Vector3.h>
#include <model/Ship.h>
#include <model/Track.h>

class PositionUpdater : public Object
{
public:
    void UpdateIfShipMoving(Ship& ship, Track& track);
    void Update(Ship& ship, Track& track);
    void CorrectAfterFloatOperations(Ship& ship);

private:
    void UpdateTrackPointIndexes(Ship& ship, Track& track);
    void UpdateZ(Ship& ship, Track& track);
    void UpdateNormals(Ship& ship, Track& track);
    void CalculateZForPoint(Track& track, int trackPointIndex, Vector3& point);
};

class PositionUpdaterResolvingFactory : public ResolvingFactory<PositionUpdater>
{
public:
    PositionUpdater* Make(Resolver& resolver) override;
};
