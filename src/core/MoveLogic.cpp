#include <lib/Math.h>
#include <lib/Exceptions.h>
#include <lib/Numeric.h>
#include <calc/Geometry.h>
#include <calc/Vector3.h>
#include <model/ShipMeasure.h>
#include <core/MoveLogic.h>

void MoveLogic::MoveShip(float timeStep, Ship& ship)
{
    if (!Numeric::FloatEquals(ship.VelocityValue, 0.0f))
    {
        float moveDistance = ship.VelocityValue * timeStep;
        if (Numeric::FloatEquals(ship.TurnAngleRadians, 0.0f))
        {
            MoveStraight(ship, moveDistance);
        }
        else
        {
            MoveAround(ship, moveDistance);
        }
    }

    if (!ship.Deviation.IsZero())
    {
        ship.CentralLine.Front.Add(ship.Deviation);
        ship.CentralLine.Rear.Add(ship.Deviation);
        ship.Deviation.Mul(0.5f);
    }
}

void MoveLogic::MoveStraight(Ship& ship, float moveDistance)
{
    Vector3 direction(ship.CentralLine.Front);
    direction.Sub(ship.CentralLine.Rear);
    direction.SetLength(moveDistance);
    ship.CentralLine.Front.Add(direction);
    ship.CentralLine.Rear.Add(direction);
}

void MoveLogic::MoveAround(Ship& ship, float moveDistance)
{
    float turnAngleAbs = Math::Abs(ship.TurnAngleRadians);

    float rearTurnRadius = ShipMeasure::YLength / Math::Sin(turnAngleAbs);
    float frontTurnRadius = rearTurnRadius * Math::Cos(turnAngleAbs);

    Vector3 pivotPoint;
    GetPivotPoint(ship, frontTurnRadius, pivotPoint);

    Assert(ship, frontTurnRadius, rearTurnRadius, pivotPoint);

    float frontCircleLength = Math::PiDouble * frontTurnRadius;
    float rearCircleLength = Math::PiDouble * rearTurnRadius;
    float frontTurnAngle = Math::PiDouble * moveDistance / frontCircleLength;
    float rearTurnAngle = Math::PiDouble * moveDistance / rearCircleLength;
    if (ship.TurnAngleRadians > 0.0f)
    {
        frontTurnAngle = -frontTurnAngle;
        rearTurnAngle = -rearTurnAngle;
    }

    ship.CentralLine.Front = Geometry::RotatePoint3d(ship.CentralLine.Front, ship.CentralLine.NormalFront, pivotPoint, frontTurnAngle);
    ship.CentralLine.Rear = Geometry::RotatePoint3d(ship.CentralLine.Rear, ship.CentralLine.NormalRear, pivotPoint, rearTurnAngle);
}

void MoveLogic::GetPivotPoint(Ship& ship, float frontTurnRadius, Vector3& pivot)
{
    if (ship.TurnAngleRadians > 0.0f)
    {
        pivot.Set(ship.CentralLine.Front);
        pivot.Sub(ship.CentralLine.Rear);
    }
    else
    {
        pivot.Set(ship.CentralLine.Rear);
        pivot.Sub(ship.CentralLine.Front);
    }
    pivot.VectorProduct(ship.CentralLine.NormalFront);
    pivot.SetLength(frontTurnRadius);
    pivot.Add(ship.CentralLine.Front);
}

void MoveLogic::Assert(Ship& ship, float frontTurnRadius, float rearTurnRadius, Vector3& pivot)
{
    if (Math::Abs(rearTurnRadius * rearTurnRadius - (frontTurnRadius * frontTurnRadius + ShipMeasure::YLength * ShipMeasure::YLength)) > 0.1f)
    {
        throw AssertException();
    }

    Vector3 frontTurnRadiusFromPivot(pivot.X, pivot.Y, pivot.Z);
    frontTurnRadiusFromPivot.Sub(ship.CentralLine.Front);
    if (Math::Abs(frontTurnRadiusFromPivot.GetLength() - frontTurnRadius) > 0.1f)
    {
        throw AssertException();
    }

    Vector3 rearTurnRadiusFromPivot(pivot.X, pivot.Y, pivot.Z);
    rearTurnRadiusFromPivot.Sub(ship.CentralLine.Rear);
    if (Math::Abs(rearTurnRadiusFromPivot.GetLength() - rearTurnRadius) > 0.1f)
    {
        throw AssertException();
    }
}
