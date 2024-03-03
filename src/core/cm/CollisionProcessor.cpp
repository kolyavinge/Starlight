#include <lib/Assert.h>
#include <calc/Vector3.h>
#include <calc/Physics.h>
#include <model/ShipMeasure.h>
#include <model/Ship.h>
#include <core/cm/TrackCollisionResult.h>
#include <core/cm/ShipCollisionResult.h>
#include <core/cm/CollisionProcessor.h>

CollisionProcessor::CollisionProcessor()
{
    _hasCollisions = false;
}

void CollisionProcessor::ProcessCollisions(Ship& ship, IArray<Ship*>& allShips, Track& track)
{
    _hasCollisions =
        ProcessTrackCollisions(ship, track) ||
        ProcessShipsCollisions(ship, allShips);
}

bool CollisionProcessor::HasCollisions()
{
    return _hasCollisions;
}

bool CollisionProcessor::ProcessTrackCollisions(Ship& ship, Track& track)
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

bool CollisionProcessor::ProcessShipsCollisions(Ship& ship, IArray<Ship*>& allShips)
{
    if (!_shipCollisionDetector.DetectCollisions(ship, allShips)) return false;
    ShipCollisionResult& collisionResult = _shipCollisionDetector.Result;
    Ship& ship1 = *collisionResult.Ship1;
    Ship& ship2 = *collisionResult.Ship2;

    ship.CentralLine = ship.PrevCentralLine;

    Vector3 ship1Velocity(ship1.GetVelocityVector());
    Vector3 ship2Velocity(ship2.GetVelocityVector());

    NewVelocityResult result = Physics::GetNewVelocityAfterCollision(
        ShipMeasure::Mass, ship1Velocity, ShipMeasure::Mass, ship2Velocity);

    if (!result.Velocity1.IsZero())
    {
        ship1.OrientationByRearPoint(ship1.CentralLine.Rear, result.Velocity1);
        ship1.ThrottleTime = ship1.VelocityFunction.GetThrottleTimeByValue(result.Velocity1.GetLength());
    }

    if (!result.Velocity2.IsZero())
    {
        ship2.OrientationByRearPoint(ship2.CentralLine.Rear, result.Velocity2);
        ship2.ThrottleTime = ship2.VelocityFunction.GetThrottleTimeByValue(result.Velocity2.GetLength());
    }

    return true;
}
