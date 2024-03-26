#include <calc/VectorCalculator.h>
#include <core/cm/TrackCollisionDetector.h>

TrackCollisionResult::TrackCollisionResult()
{
    Init();
}

void TrackCollisionResult::Init()
{
    FromTrackPoint.Set(0.0f, 0.0f, 0.0f);
    ToTrackPoint.Set(0.0f, 0.0f, 0.0f);
    OppositeTrackPoint.Set(0.0f, 0.0f, 0.0f);
    FromIndex = 0;
    ToIndex = 0;
}

bool TrackCollisionDetector::DetectCollisions(Ship& ship, Track& track)
{
    return
        DetectCollisions(track, ship.CentralLine.TrackPointIndexFront, ship.Border.UpLeft) ||
        DetectCollisions(track, ship.CentralLine.TrackPointIndexFront, ship.Border.UpRight) ||
        DetectCollisions(track, ship.CentralLine.TrackPointIndexRear, ship.Border.DownLeft) ||
        DetectCollisions(track, ship.CentralLine.TrackPointIndexRear, ship.Border.DownRight);
}

bool TrackCollisionDetector::DetectCollisions(Track& track, int trackPointIndex, Vector3& point)
{
    int toTrackPointIndex = track.GetNextTrackPointIndex(trackPointIndex);

    return
        DetectCollisions(track.InsidePoints, track.OutsidePoints, trackPointIndex, toTrackPointIndex, point) ||
        DetectCollisions(track.OutsidePoints, track.InsidePoints, trackPointIndex, toTrackPointIndex, point);
}

bool TrackCollisionDetector::DetectCollisions(
    TrackPoints& trackPoints, TrackPoints& oppositeTrackPoints, int fromTrackPointIndex, int toTrackPointIndex, Vector3& point)
{
    Vector3& from = trackPoints[fromTrackPointIndex];
    Vector3& to = trackPoints[toTrackPointIndex];
    Vector3& oppositeFrom = oppositeTrackPoints[fromTrackPointIndex];
    if (!VectorCalculator::IsPointInQuadrant(from, to, oppositeFrom, point)) // out of track area
    {
        Result.FromTrackPoint = from;
        Result.ToTrackPoint = to;
        Result.OppositeTrackPoint = oppositeFrom;
        Result.FromIndex = fromTrackPointIndex;
        Result.ToIndex = toTrackPointIndex;

        return true;
    }

    return false;
}

TrackCollisionDetector* TrackCollisionDetectorResolvingFactory::Make(Resolver&)
{
    return new TrackCollisionDetector();
}
