#include <lib/Numeric.h>
#include <calc/Vector3.h>
#include <core/LapCounter.h>

LapCounter::LapCounter()
{
    Init();
}

void LapCounter::Init()
{
    _completedTrackPoints.InitItems(false);
    _completedLapsCount = 0;
    _prevTrackPointIndex = 0;
}

void LapCounter::CheckLap(Ship& ship, Track& track)
{
    if (!ship.IsMoving()) return;
    _prevTrackPointIndex = ship.CentralLine.TrackPointIndexFront;
    _completedTrackPoints[ship.CentralLine.TrackPointIndexFront] = true;
    bool isStartFinishLineCrossed = IsStartFinishLineCrossed(ship, track);
    if (isStartFinishLineCrossed &&
        IsShipMovingInStraightDirection(ship, track) &&
        AreTrackPointsCompleted(track.PointsCount))
    {
        _completedLapsCount++;
    }
    if (isStartFinishLineCrossed)
    {
        _completedTrackPoints.InitItems(false);
        _completedTrackPoints[ship.CentralLine.TrackPointIndexFront] = true;
    }
}

int LapCounter::GetCompletedLapsCount()
{
    return _completedLapsCount;
}

bool LapCounter::IsStartFinishLineCrossed(Ship& ship, Track& track)
{
    return
        Numeric::Between(track.StartFinishLineIndex, _prevTrackPointIndex, ship.CentralLine.TrackPointIndexFront) ||
        Numeric::Between(track.StartFinishLineIndex, ship.CentralLine.TrackPointIndexFront, _prevTrackPointIndex);
}

bool LapCounter::IsShipMovingInStraightDirection(Ship& ship, Track& track)
{
    Vector3 shipStraightDirection(ship.CentralLine.Front);
    shipStraightDirection.Sub(ship.CentralLine.Rear);

    return track.IsShipMovingInStraightDirection(shipStraightDirection);
}

bool LapCounter::AreTrackPointsCompleted(int trackPointsCount)
{
    const int batchSize = 10;
    for (int i = 0; i < trackPointsCount; i++)
    {
        if (!IsCompletedPointExist(i, i + batchSize, trackPointsCount))
        {
            return false;
        }
    }

    return true;
}

bool LapCounter::IsCompletedPointExist(int startIndex, int endIndex, int trackPointsCount)
{
    for (int i = startIndex; i < endIndex && i < trackPointsCount; i++)
    {
        if (_completedTrackPoints[i]) return true;
    }

    return false;
}
