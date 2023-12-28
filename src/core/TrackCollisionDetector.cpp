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
        DetectCollisions(point, track, track.InsidePoints, track.OutsidePoints, result) ||
        DetectCollisions(point, track, track.OutsidePoints, track.InsidePoints, result);
}

bool TrackCollisionDetector::DetectCollisions(
    Vector3d& point, Track& track, TrackPoints& trackPoints, TrackPoints& oppositeTrackPoints, TrackCollisionResult& result)
{
    int fromIndex = track.GetNearestTrackPointIndex(trackPoints, point);
    int toIndex = fromIndex + 1;
    if (toIndex == track.PointsCount) toIndex = 0;

    Vector3d& from = trackPoints[fromIndex];
    Vector3d& to = trackPoints[toIndex];
    Vector3d& opposite = oppositeTrackPoints[fromIndex];
    if (DetectCollisions(from, to, opposite, point))
    {
        result.From = from;
        result.To = to;
        result.FromIndex = fromIndex;
        result.ToIndex = toIndex;

        return true;
    }

    return false;
}

bool TrackCollisionDetector::DetectCollisions(Vector3d& center, Vector3d edge, Vector3d inside, Vector3d point)
{
    point.Sub(center);
    if (point.IsZero()) return true;

    edge.Sub(center);
    inside.Sub(center);

    Vector3d checkCollision(point);
    checkCollision.VectorProduct(edge);
    if (checkCollision.IsZero()) return true;
    checkCollision.Normalize();

    Vector3d noCollision(inside);
    noCollision.VectorProduct(edge);
    noCollision.Normalize();

    Vector3d diff(noCollision);
    diff.Sub(checkCollision);
    bool collided = diff.GetLengthSquared() > 1.0f;

    return collided;
}
