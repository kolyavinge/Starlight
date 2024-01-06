#include <core/TrackCollisionDetector.h>

bool TrackCollisionDetector::DetectCollisions(Ship& ship, Track& track)
{
    Result.Init();

    return
        DetectCollisions(track, ship.CentralLine.TrackPointIndexFront, ship.Border.UpLeft) ||
        DetectCollisions(track, ship.CentralLine.TrackPointIndexFront, ship.Border.UpRight) ||
        DetectCollisions(track, ship.CentralLine.TrackPointIndexRear, ship.Border.DownLeft) ||
        DetectCollisions(track, ship.CentralLine.TrackPointIndexRear, ship.Border.DownRight);
}

bool TrackCollisionDetector::DetectCollisions(Track& track, int trackPointIndex, Vector3& point)
{
    return
        DetectCollisions(track, track.InsidePoints, track.OutsidePoints, trackPointIndex, point) ||
        DetectCollisions(track, track.OutsidePoints, track.InsidePoints, trackPointIndex, point);
}

bool TrackCollisionDetector::DetectCollisions(
    Track& track, TrackPoints& trackPoints, TrackPoints& oppositeTrackPoints, int trackPointIndex, Vector3& point)
{
    int fromIndex = trackPointIndex;
    int toIndex = fromIndex + 1;
    if (toIndex == track.PointsCount) toIndex = 0;
    Vector3& from = trackPoints[fromIndex];
    Vector3& to = trackPoints[toIndex];
    Vector3& opposite = oppositeTrackPoints[fromIndex];
    if (DetectCollisions(from, to, opposite, point))
    {
        Result.FromTrackPoint = from;
        Result.ToTrackPoint = to;
        Result.OppositeTrackPoint = opposite;
        Result.FromIndex = fromIndex;
        Result.ToIndex = toIndex;

        return true;
    }

    return false;
}

bool TrackCollisionDetector::DetectCollisions(Vector3& center, Vector3 edge, Vector3 inside, Vector3 point)
{
    point.Sub(center);
    if (point.IsZero()) return true;

    edge.Sub(center);
    inside.Sub(center);

    Vector3 checkCollision(point);
    checkCollision.VectorProduct(edge);
    if (checkCollision.IsZero()) return true;
    checkCollision.Normalize();

    Vector3 noCollision(inside);
    noCollision.VectorProduct(edge);
    noCollision.Normalize();

    Vector3 diff(noCollision);
    diff.Sub(checkCollision);
    bool collided = diff.GetLengthSquared() > 1.0f;

    return collided;
}
