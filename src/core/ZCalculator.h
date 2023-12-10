#pragma once

#include "lib/Object.h"
#include "calc/Vector3d.h"
#include "model/Ship.h"
#include "model/Track.h"

class ZCalculator : public Object
{
public:
    void CalculateZ(Ship& ship, Track& track);

private:
    void CalculateForPoint(Vector3d& point, Track& track);
    int GetNearestTrackPointIndex(Vector3d& point, Track& track);
};
