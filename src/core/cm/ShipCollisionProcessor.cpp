#include <calc/Vector3.h>
#include <calc/Physics.h>
#include <model/ShipMeasure.h>
#include <model/Ship.h>
#include <core/cm/ShipCollisionResult.h>
#include <core/cm/ShipCollisionProcessor.h>

bool ShipCollisionProcessor::ProcessShipsCollisions(Ship& ship, IArray<Ship*>& allShips)
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
