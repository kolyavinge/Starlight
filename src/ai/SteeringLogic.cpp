#include <calc/Vector3.h>
#include <ai/SteeringLogic.h>

SteeringLogic::SteeringLogic(ShipController& controller) :
    _controller(controller)
{
}

void SteeringLogic::Update(Ship& ship, Track& track)
{
    _controller.SetShip(ship);
    ProcessSteering(ship);
    ProcessThrottle(ship, track);
}

void SteeringLogic::ProcessSteering(Ship& ship)
{
    if (ship.AIData.MovingDirections.ResultDirection.IsZero())
    {
        return;
    }

    Vector3 straight(ship.CentralLine.Front);
    straight.Sub(ship.CentralLine.Rear);
    straight.Normalize();

    float dotProduct = straight.DotProduct(ship.AIData.MovingDirections.ResultDirection);
    if (dotProduct >= ship.AIData.StraightDirectionLimit)
    {
        _controller.ReleaseTurn();
    }
    else
    {
        straight.VectorProduct(ship.AIData.MovingDirections.ResultDirection);
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
}

void SteeringLogic::ProcessThrottle(Ship& ship, Track& track)
{
    _controller.ActivateThrottle();

    TrackPointInfo& pi = track.PointInfos[ship.CentralLine.TrackPointIndexFront];
    if (pi.IsTurn() &&
        pi.Radius <= 50.0f &&
        ship.VelocityValue > (ship.VelocityFunction.MaxVelocity - 2.0f))
    {
        _controller.ReleaseThrottle();
    }
}

SteeringLogic* SteeringLogicResolvingFactory::Make(Resolver& resolver)
{
    return new SteeringLogic(resolver.Resolve<ShipController>());
}
