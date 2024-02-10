#include <lib/Numeric.h>
#include <calc/Vector3.h>
#include <core/LapChecker.h>

LapChecker::LapChecker()
{
    Init();
}

void LapChecker::Init()
{
    _completedTrackPoints.InitZero();
}

bool LapChecker::IsLapCompleted(Ship& ship, Track& track)
{
    if (!ship.IsMoving()) return false;
    if (!IsShipMovingInStraightDirection(ship, track)) return false;
    CompleteTrackPoints(ship, track);
    bool isLapCompleted = false;
    if (IsStartFinishLineCrossed(ship, track))
    {
        isLapCompleted = AllTrackPointsCompleted(track.PointsCount);
        _completedTrackPoints.InitZero();
        _completedTrackPoints.InitRange(track.StartFinishLineIndex, ship.CentralLine.TrackPointIndexFront, true);
    }

    return isLapCompleted;
}

void LapChecker::CompleteTrackPoints(Ship& ship, Track& track)
{
    for (int i = ship.CentralLine.TrackPointIndexRear; i != ship.CentralLine.TrackPointIndexFront; i = track.GetNextTrackPointIndex(i))
    {
        _completedTrackPoints[i] = true;
    }
}

bool LapChecker::IsStartFinishLineCrossed(Ship& ship, Track& track)
{
    for (int i = ship.CentralLine.TrackPointIndexRear; i != ship.CentralLine.TrackPointIndexFront; i = track.GetNextTrackPointIndex(i))
    {
        if (i == track.StartFinishLineIndex) return true;
    }

    return false;
}

bool LapChecker::IsShipMovingInStraightDirection(Ship& ship, Track& track)
{
    if (ship.CentralLine.TrackPointIndexFront == ship.CentralLine.TrackPointIndexRear)
    {
        return false;
    }

    return track.IsShipMovingInStraightDirection(ship.CentralLine.TrackPointIndexFront, ship.CentralLine.TrackPointIndexRear);
}

bool LapChecker::AllTrackPointsCompleted(int trackPointsCount)
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
