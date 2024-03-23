#pragma once

#include <lib/Object.h>
#include <lib/Array.h>
#include <model/Ship.h>
#include <model/Track.h>

class LapChecker : public Object
{
    Array<bool, TrackMaxPoints> _completedTrackPoints;

public:
    LapChecker();

    void Init();
    bool IsLapCompleted(Ship& ship, Track& track);

private:
    void CompleteTrackPoints(Ship& ship);
    bool IsStartFinishLineCrossed(Ship& ship, Track& track);
    bool IsShipMovingInStraightDirection(Ship& ship, Track& track);
    bool AllTrackPointsCompleted(int trackPointsCount);
    bool AnyTrackPointsCompleted(int fromTrackPointIndex, int toTrackPointIndex);
};
