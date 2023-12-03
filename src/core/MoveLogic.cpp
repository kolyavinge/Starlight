#include "lib/Math.h"
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
        direction.Normalize();
        direction.Mul(moveDistance);
        ship.FrontMiddlePoint.Add(direction);
        ship.RearMiddlePoint.Add(direction);
    }
    else
    {
        float turnAngleAbs = Math::Abs(ship.TurnAngleRadians);

        float rearTurnRadius = Ship::YLength / Math::Sin(turnAngleAbs);
        float frontTurnRadius = rearTurnRadius * Math::Cos(turnAngleAbs);

        float pivotX = ship.FrontMiddlePoint.X + (ship.TurnAngleRadians > 0.0f ? frontTurnRadius : -frontTurnRadius);
        float pivotY = ship.FrontMiddlePoint.Y;

        float frontTurnCircleLength = Math::PiDouble * frontTurnRadius;
        float rearTurnCircleLength = Math::PiDouble * rearTurnRadius;

        float frontTurnAngle = Math::PiDouble * moveDistance / frontTurnCircleLength;
        float rearTurnAngle = Math::PiDouble * moveDistance / rearTurnCircleLength;
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
