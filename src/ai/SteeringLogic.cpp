#include <calc/Vector3.h>
#include <ai/SteeringLogic.h>

void SteeringLogic::Update(Ship& ship)
{
    _controller.SetShip(ship);

    Vector3 straight(ship.CentralLine.Front);
    straight.Sub(ship.CentralLine.Rear);
    straight.Normalize();

    float dotProduct = straight.DotProduct(ship.AIMovingDirection);
    if (dotProduct >= 0.999f)
    {
        _controller.ReleaseTurn();
    }
    else
    {
        straight.VectorProduct(ship.AIMovingDirection);
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
