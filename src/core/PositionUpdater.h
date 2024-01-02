#pragma once

#include <lib/Object.h>
#include <calc/Vector3d.h>
#include <model/Ship.h>
#include <model/Track.h>

class PositionUpdater : public Object
{
public:
    void UpdateIfShipMoving(Ship& ship, Track& track);
    void Update(Ship& ship, Track& track);

private:
    void UpdateTrackPointIndexes(Ship& ship, Track& track);
    void UpdateZ(Ship& ship, Track& track);
    void CalculateZForPoint(Track& track, int trackPointIndex, Vector3d& point, Vector3d& normal);
};
