#include <model/Track.h>
#include <core/Constants.h>
#include <core/RaceUpdater.h>

void RaceUpdater::Update(
    Ship& player,
    Track& track,
    Camera& camera)
{
    SaveCurrentShipsPositions(player);
    _positionUpdater.UpdateIfShipMoving(player, track);
    float timeStep = Constants::TimeStep;
    _turnAngleCalculator.CalculateTurnAngle(player);
    _velocityCalculator.CalculateVelocity(timeStep, player);
    _moveLogic.MoveShip(timeStep, player);
    _borderUpdater.Update(player);
    _collisionProcessor.ProcessCollisions(player, track);
    if (_collisionProcessor.HasCollisions())
    {
        _borderUpdater.Update(player);
    }
    _positionCorrector.CorrectAfterFloatOperations(player);
    _lapCounter.CheckLap(player, track);
    camera.SetFrontView(player);
}

void RaceUpdater::SaveCurrentShipsPositions(Ship& player)
{
    player.PrevCentralLine = player.CentralLine;
}
