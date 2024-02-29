#include <calc/Vector3.h>
#include <ai/SteeringLogic.h>

void SteeringLogic::Update(Ship& ship)
{
    _controller.SetShip(ship);

    Vector3 straight(ship.CentralLine.Front);
    straight.Sub(ship.CentralLine.Rear);
    straight.Normalize();

    float dotProduct = straight.DotProduct(ship.AIData.MovingDirection);
    if (dotProduct >= ship.AIData.StraightDirectionLimit)
    {
        _controller.ReleaseTurn();
    }
    else
    {
        straight.VectorProduct(ship.AIData.MovingDirection);
        if (straight.IsZero())
        {
            _controller.ReleaseTurn();
        }
        else if (straight.Z > 0.0f)
        {
            _controller.TurnLeft();
        }
        else
        {
            _controller.TurnRight();
        }
    }

    _controller.ActivateThrottle();
}
