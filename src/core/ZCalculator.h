#pragma once

#include <lib/Object.h>
#include <calc/Vector3d.h>
#include <model/Ship.h>
#include <model/Track.h>

class ZCalculator : public Object
{
public:
    void CalculateZIfShipMoving(Ship& ship, Track& track);
    void CalculateZ(Ship& ship, Track& track);

private:
    void CalculateForPoint(Vector3d& point, Vector3d& normal, Track& track);
    float GetNearestMiddlePointZ(Array<Vector3d, TrackMaxMiddlePoints>& middlePoints, Vector3d& point);
    int GetNearestTrackPointIndex(Vector3d& point, Track& track);
};
