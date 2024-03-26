#include <lib/Assert.h>
#include <calc/Vector3.h>
#include <model/Ship.h>
#include <core/cm/TrackCollisionProcessor.h>

bool TrackCollisionProcessor::ProcessTrackCollisions(Ship& ship, Track& track)
{
    if (!_trackCollisionDetector.DetectCollisions(ship, track)) return false;
    TrackCollisionResult& collisionResult = _trackCollisionDetector.Result;

    Vector3 frontDirection(ship.CentralLine.Front);
    frontDirection.Sub(ship.PrevCentralLine.Front);
    Assert::False(frontDirection.IsZero());

    ship.CentralLine = ship.PrevCentralLine;

    Vector3 opposite(collisionResult.OppositeTrackPoint);
    opposite.Sub(collisionResult.FromTrackPoint);
    opposite.SetLength(0.5f);
    ship.Deviation.Add(opposite);

    ship.ThrottleTime *= 0.5f;

    return true;
}

TrackCollisionProcessor* TrackCollisionProcessorResolvingFactory::Make(Resolver&)
{
    return new TrackCollisionProcessor();
}
