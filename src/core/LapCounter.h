#pragma once

#include <lib/Object.h>
#include <lib/Array.h>
#include <model/Ship.h>
#include <model/Track.h>

class LapCounter : public Object
{
    Array<bool, TrackMaxPoints> _completedTrackPoints;
    int _completedLapsCount;
    int _prevTrackPointIndex;

public:
    LapCounter();

    void Init();
    void CheckLap(Ship& ship, Track& track);
    int GetCompletedLapsCount();

private:
    bool IsStartFinishLineCrossed(Ship& ship, Track& track);
    bool IsShipMovingInStraightDirection(Ship& ship, Track& track);
    bool AreTrackPointsCompleted(int trackPointsCount);
    bool IsCompletedPointExist(int startIndex, int endIndex, int trackPointsCount);
};
