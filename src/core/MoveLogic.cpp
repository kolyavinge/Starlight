#include "lib/Math.h"
#include "lib/Exceptions.h"
#include "lib/Numeric.h"
#include "calc/Geometry.h"
#include "calc/Vector3d.h"
#include "core/MoveLogic.h"

void MoveLogic::Move(float timeStep, Ship& ship)
{
    float moveDistance = ship.CurrentVelocityValue * timeStep;

    if (Numeric::FloatEquals(moveDistance, 0.0f))
    {
        return;
    }

    if (Numeric::FloatEquals(ship.TurnAngleRadians, 0.0f))
    {
        Vector3d direction(ship.FrontMiddlePoint);
        direction.Sub(ship.RearMiddlePoint);
        direction.SetLength(moveDistance);
        ship.FrontMiddlePoint.Add(direction);
        ship.RearMiddlePoint.Add(direction);
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
            ship.FrontMiddlePoint.X, ship.FrontMiddlePoint.Y,
            pivotX, pivotY,
            frontTurnAngle,
            &ship.FrontMiddlePoint.X, &ship.FrontMiddlePoint.Y);

        Geometry::RotatePoint(
            ship.RearMiddlePoint.X, ship.RearMiddlePoint.Y,
            pivotX, pivotY,
            rearTurnAngle,
            &ship.RearMiddlePoint.X, &ship.RearMiddlePoint.Y);
    }
}

void MoveLogic::GetPivotPoint(Ship& ship, float frontTurnRadius, float* pivotX, float* pivotY)
{
    float resultX, resultY;

    Geometry::RotatePoint(
        ship.RearMiddlePoint.X, ship.RearMiddlePoint.Y,
        ship.FrontMiddlePoint.X, ship.FrontMiddlePoint.Y,
        ship.TurnAngleRadians > 0.0f ? Math::PiHalf : -Math::PiHalf,
        &resultX, &resultY);

    Vector3d pivotVector(resultX, resultY, 0.0f);
    pivotVector.Sub(ship.FrontMiddlePoint);
    pivotVector.SetLength(frontTurnRadius);
    pivotVector.Add(ship.FrontMiddlePoint);

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
    frontTurnRadiusFromPivot.Sub(ship.FrontMiddlePoint);
    if (Math::Abs(frontTurnRadiusFromPivot.GetLength() - frontTurnRadius) > 0.1f)
    {
        throw AssertException();
    }

    Vector3d rearTurnRadiusFromPivot(pivotX, pivotY, 0.0f);
    rearTurnRadiusFromPivot.Sub(ship.RearMiddlePoint);
    if (Math::Abs(rearTurnRadiusFromPivot.GetLength() - rearTurnRadius) > 0.1f)
    {
        throw AssertException();
    }
}
