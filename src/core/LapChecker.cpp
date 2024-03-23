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
    CompleteTrackPoints(ship);
    bool isLapCompleted = false;
    if (IsStartFinishLineCrossed(ship, track))
    {
        isLapCompleted = AllTrackPointsCompleted(track.PointsCount);
        _completedTrackPoints.InitZero();
        _completedTrackPoints.InitRange(track.StartFinishLineIndex, ship.CentralLine.TrackPointIndexFront, true);
    }

    return isLapCompleted;
}

void LapChecker::CompleteTrackPoints(Ship& ship)
{
    _completedTrackPoints[ship.CentralLine.TrackPointIndexFront] = true;
    _completedTrackPoints[ship.CentralLine.TrackPointIndexRear] = true;
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
    const int step = 100;
    for (int i = 0; i < trackPointsCount; i += step)
    {
        if (!AnyTrackPointsCompleted(i, i + step))
        {
            return false;
        }
    }

    return true;
}

bool LapChecker::AnyTrackPointsCompleted(int fromTrackPointIndex, int toTrackPointIndex)
{
    for (int i = fromTrackPointIndex; i < toTrackPointIndex; i++)
    {
        if (_completedTrackPoints[i])
        {
            return true;
        }
    }

    return false;
}
