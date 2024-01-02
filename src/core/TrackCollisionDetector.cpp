#include <core/TrackCollisionDetector.h>

bool TrackCollisionDetector::DetectCollisions(Ship& ship, Track& track, TrackCollisionResult& result)
{
    return
        DetectCollisions(track, ship.CentralLine.TrackPointIndexFront, ship.Border.UpLeft, result) ||
        DetectCollisions(track, ship.CentralLine.TrackPointIndexFront, ship.Border.UpRight, result) ||
        DetectCollisions(track, ship.CentralLine.TrackPointIndexRear, ship.Border.DownLeft, result) ||
        DetectCollisions(track, ship.CentralLine.TrackPointIndexRear, ship.Border.DownRight, result);
}

bool TrackCollisionDetector::DetectCollisions(Track& track, int& nearTrackPointIndex, Vector3d& point, TrackCollisionResult& result)
{
    return
        DetectCollisions(track, track.InsidePoints, track.OutsidePoints, nearTrackPointIndex, point, result) ||
        DetectCollisions(track, track.OutsidePoints, track.InsidePoints, nearTrackPointIndex, point, result);
}

bool TrackCollisionDetector::DetectCollisions(
    Track& track, TrackPoints& trackPoints, TrackPoints& oppositeTrackPoints, int& nearTrackPointIndex, Vector3d& point, TrackCollisionResult& result)
{
    nearTrackPointIndex = track.GetNearestTrackPointIndex(trackPoints, point, nearTrackPointIndex);
    int toIndex = nearTrackPointIndex + 1;
    if (toIndex == track.PointsCount) toIndex = 0;

    Vector3d& from = trackPoints[nearTrackPointIndex];
    Vector3d& to = trackPoints[toIndex];
    Vector3d& opposite = oppositeTrackPoints[nearTrackPointIndex];
    if (DetectCollisions(from, to, opposite, point))
    {
        result.FromTrackPoint = from;
        result.ToTrackPoint = to;
        result.OppositeTrackPoint = opposite;
        result.FromIndex = nearTrackPointIndex;
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
