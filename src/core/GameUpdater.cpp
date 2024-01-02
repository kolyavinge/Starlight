#include <core/GameConstants.h>
#include <core/GameUpdater.h>

GameUpdater::GameUpdater(
    Ship& player,
    Track& track,
    GameCamera& camera) :
    _player(player),
    _track(track),
    _camera(camera)
{
}

void GameUpdater::Update()
{
    SaveCurrentShipsPositions();
    _positionUpdater.UpdateIfShipMoving(_player, _track);
    float timeStep = GameConstants::TimeStepMax;
    _turnAngleCalculator.CalculateTurnAngle(_player);
    _velocityCalculator.CalculateVelocity(timeStep, _player);
    _moveLogic.MoveShip(timeStep, _player);
    _borderUpdater.Update(_player);
    _collisionProcessor.ProcessCollisions(_player, _track);
    _positionCorrector.CorrectAfterFloatOperations(_player);
    _camera.Update(_player);
}

void GameUpdater::SaveCurrentShipsPositions()
{
    _player.PrevCentralLine = _player.CentralLine;
}
