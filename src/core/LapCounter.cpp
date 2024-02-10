#include <lib/Numeric.h>
#include <calc/Vector3.h>
#include <core/LapCounter.h>

LapCounter::LapCounter()
{
    _completedTrackPoints.InitZero();
    _prevTrackPointIndex = 0;
}

void LapCounter::Init(Ship& ship)
{
    _completedTrackPoints.InitZero();
    _prevTrackPointIndex = ship.CentralLine.TrackPointIndexFront;
}

bool LapCounter::IsLapCompleted(Ship& ship, Track& track)
{
    if (!ship.IsMoving()) return false;
    if (!IsShipMovingInStraightDirection(ship, track)) return false;
    bool isCompleted = false;
    CompleteTrackPoints(ship, track);
    bool isStartFinishLineCrossed = IsStartFinishLineCrossed(ship, track);
    if (isStartFinishLineCrossed && AllTrackPointsCompleted(track.PointsCount))
    {
        isCompleted = true;
    }
    if (isStartFinishLineCrossed)
    {
        _completedTrackPoints.InitZero();
        _completedTrackPoints.InitRange(track.StartFinishLineIndex, ship.CentralLine.TrackPointIndexFront, true);
    }
    _prevTrackPointIndex = ship.CentralLine.TrackPointIndexFront;

    return isCompleted;
}

void LapCounter::CompleteTrackPoints(Ship& ship, Track& track)
{
    for (int i = ship.CentralLine.TrackPointIndexRear; i != ship.CentralLine.TrackPointIndexFront; i = track.GetNextTrackPointIndex(i))
    {
        _completedTrackPoints[i] = true;
    }
}

bool LapCounter::IsStartFinishLineCrossed(Ship& ship, Track& track)
{
    for (int i = ship.CentralLine.TrackPointIndexRear; i != ship.CentralLine.TrackPointIndexFront; i = track.GetNextTrackPointIndex(i))
    {
        if (i == track.StartFinishLineIndex) return true;
    }

    return false;
}

bool LapCounter::IsShipMovingInStraightDirection(Ship& ship, Track& track)
{
    if (ship.CentralLine.TrackPointIndexFront == ship.CentralLine.TrackPointIndexRear)
    {
        return false;
    }

    return track.IsShipMovingInStraightDirection(ship.CentralLine.TrackPointIndexFront, ship.CentralLine.TrackPointIndexRear);
}

bool LapCounter::AllTrackPointsCompleted(int trackPointsCount)
{
    for (int i = 0; i < trackPointsCount; i++)
    {
        if (!_completedTrackPoints[i])
        {
            return false;
        }
    }

    return true;
}
