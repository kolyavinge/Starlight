#include <core/GameConstants.h>
#include <core/TrackCollisionDetector.h>

bool TrackCollisionDetector::DetectCollisions(Ship& ship, Track& track, TrackCollisionResult& result)
{
    return
        DetectCollisions(ship.Border.UpLeft, track, result) ||
        DetectCollisions(ship.Border.UpRight, track, result) ||
        DetectCollisions(ship.Border.DownLeft, track, result) ||
        DetectCollisions(ship.Border.DownRight, track, result);
}

bool TrackCollisionDetector::DetectCollisions(Vector3d& point, Track& track, TrackCollisionResult& result)
{
    return
        DetectCollisions(point, track.InsidePoints, track.PointsCount, result) ||
        DetectCollisions(point, track.OutsidePoints, track.PointsCount, result);
}

bool TrackCollisionDetector::DetectCollisions(Vector3d& point, TrackPoints& trackPoints, int pointsCount, TrackCollisionResult& result)
{
    for (int i = 0; i < pointsCount - 1; i++)
    {
        Vector3d& from = trackPoints[i];
        Vector3d& to = trackPoints[i + 1];
        if (DetectCollisions(from, to, point))
        {
            result.From = from;
            result.To = to;
            result.FromIndex = i;
            result.ToIndex = i + 1;

            return true;
        }
    }

    Vector3d& from = trackPoints[pointsCount - 1];
    Vector3d& to = trackPoints[0];
    if (DetectCollisions(from, to, point))
    {
        result.From = from;
        result.To = to;
        result.FromIndex = pointsCount - 1;
        result.ToIndex = 0;

        return true;
    }

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
