#include "lib/Math.h"
#include "lib/Exceptions.h"
#include "lib/Numeric.h"
#include "calc/Geometry.h"
#include "calc/Vector3d.h"
#include "core/MoveLogic.h"

void MoveLogic::MoveShip(float timeStep, Ship& ship)
{
    float moveDistance = ship.VelocityValue * timeStep;

    if (Numeric::FloatEquals(moveDistance, 0.0f))
    {
        return;
    }

    if (Numeric::FloatEquals(ship.TurnAngleRadians, 0.0f))
    {
        Vector3d direction(ship.CentralLine.Front);
        direction.Sub(ship.CentralLine.Rear);
        direction.SetLength(moveDistance);
        ship.CentralLine.Front.Add(direction);
        ship.CentralLine.Rear.Add(direction);
    }
    else
    {
        float turnAngleAbs = Math::Abs(ship.TurnAngleRadians);

        float rearTurnRadius = ShipMeasure::YLength / Math::Sin(turnAngleAbs);
        float frontTurnRadius = rearTurnRadius * Math::Cos(turnAngleAbs);

        float pivotX, pivotY;
        GetPivotPoint(ship, frontTurnRadius, &pivotX, &pivotY);

        Assert(ship, frontTurnRadius, rearTurnRadius, pivotX, pivotY);

        float frontCircleLength = Math::PiDouble * frontTurnRadius;
        float rearCircleLength = Math::PiDouble * rearTurnRadius;

        float frontTurnAngle = Math::PiDouble * moveDistance / frontCircleLength;
        float rearTurnAngle = Math::PiDouble * moveDistance / rearCircleLength;
        if (ship.TurnAngleRadians > 0.0f)
        {
            frontTurnAngle = -frontTurnAngle;
            rearTurnAngle = -rearTurnAngle;
        }

        Geometry::RotatePoint(
            ship.CentralLine.Front.X, ship.CentralLine.Front.Y,
            pivotX, pivotY,
            frontTurnAngle,
            &ship.CentralLine.Front.X, &ship.CentralLine.Front.Y);

        Geometry::RotatePoint(
            ship.CentralLine.Rear.X, ship.CentralLine.Rear.Y,
            pivotX, pivotY,
            rearTurnAngle,
            &ship.CentralLine.Rear.X, &ship.CentralLine.Rear.Y);
    }
}

void MoveLogic::GetPivotPoint(Ship& ship, float frontTurnRadius, float* pivotX, float* pivotY)
{
    float resultX, resultY;

    Geometry::RotatePoint(
        ship.CentralLine.Rear.X, ship.CentralLine.Rear.Y,
        ship.CentralLine.Front.X, ship.CentralLine.Front.Y,
        ship.TurnAngleRadians > 0.0f ? Math::PiHalf : -Math::PiHalf,
        &resultX, &resultY);

    Vector3d pivotVector(resultX, resultY, 0.0f);
    pivotVector.Sub(ship.CentralLine.Front);
    pivotVector.SetLength(frontTurnRadius);
    pivotVector.Add(ship.CentralLine.Front);

    *pivotX = pivotVector.X;
    *pivotY = pivotVector.Y;
}

void MoveLogic::Assert(Ship& ship, float frontTurnRadius, float rearTurnRadius, float pivotX, float pivotY)
{
    if (Math::Abs(rearTurnRadius * rearTurnRadius - (frontTurnRadius * frontTurnRadius + ShipMeasure::YLength * ShipMeasure::YLength)) > 0.1f)
    {
        throw AssertException();
    }

    Vector3d frontTurnRadiusFromPivot(pivotX, pivotY, 0.0f);
    frontTurnRadiusFromPivot.Sub(ship.CentralLine.Front);
    if (Math::Abs(frontTurnRadiusFromPivot.GetLength() - frontTurnRadius) > 0.1f)
    {
        throw AssertException();
    }

    Vector3d rearTurnRadiusFromPivot(pivotX, pivotY, 0.0f);
    rearTurnRadiusFromPivot.Sub(ship.CentralLine.Rear);
    if (Math::Abs(rearTurnRadiusFromPivot.GetLength() - rearTurnRadius) > 0.1f)
    {
        throw AssertException();
    }
}
