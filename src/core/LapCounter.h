#pragma once

#include <lib/Object.h>
#include <lib/Array.h>
#include <model/Ship.h>
#include <model/Track.h>

class LapCounter : public Object
{
    Array<bool, TrackMaxPoints> _completedTrackPoints;
    int _prevTrackPointIndex;

public:
    LapCounter();

    void Init(Ship& ship);
    bool IsLapCompleted(Ship& ship, Track& track);

private:
    void CompleteTrackPoints(Ship& ship, Track& track);
    bool IsStartFinishLineCrossed(Ship& ship, Track& track);
    bool IsShipMovingInStraightDirection(Ship& ship, Track& track);
    bool AllTrackPointsCompleted(int trackPointsCount);
};
