#include "core/GameConstants.h"
#include "core/TrackCollisionDetector.h"

bool TrackCollisionDetector::DetectCollisions(Ship& ship, Track& track)
{
    return
        DetectCollisions(ship.Border.UpLeft, track) ||
        DetectCollisions(ship.Border.UpRight, track) ||
        DetectCollisions(ship.Border.DownLeft, track) ||
        DetectCollisions(ship.Border.DownRight, track);
}

bool TrackCollisionDetector::DetectCollisions(Vector3d& point, Track& track)
{
    Vector3d from, to;
    // inside track points
    for (int i = 0; i < track.PointsCount - 1; i++)
    {
        from = track.InsidePoints[i];
        to = track.InsidePoints[i + 1];
        if (DetectCollisions(from, to, point)) return true;
    }

    from = track.InsidePoints[track.PointsCount - 1];
    to = track.InsidePoints[0];
    if (DetectCollisions(from, to, point)) return true;

    // outside track points
    for (int i = 0; i < track.PointsCount - 1; i++)
    {
        from = track.OutsidePoints[i];
        to = track.OutsidePoints[i + 1];
        if (DetectCollisions(from, to, point)) return true;
    }

    from = track.OutsidePoints[track.PointsCount - 1];
    to = track.OutsidePoints[0];
    if (DetectCollisions(from, to, point)) return true;

    return false;
}

bool TrackCollisionDetector::DetectCollisions(Vector3d& from, Vector3d& to, Vector3d& point)
{
    return _segmentIntersector.IsPointIntersected(
        from.X, from.Y,
        to.X, to.Y,
        point.X, point.Y,
        GameConstants::PointRadius);
}
