#include "core/GameConstants.h"
#include "core/GameUpdater.h"

GameUpdater::GameUpdater(
    Ship& player,
    GameCamera& camera) :
    _player(player),
    _camera(camera)
{
}

void GameUpdater::Update()
{
    float timeStep = GameConstants::TimeStepMax;
    _turnAngleCalculator.CalculateTurnAngle(_player);
    _velocityCalculator.CalculateVelocity(timeStep, _player);
    _moveLogic.MoveShip(timeStep, _player);
    _collisionDetector.DetectCollisions(_player);
    _positionCorrector.CorrectAfterFloatOperations(_player);
    _borderUpdater.Update(_player);
    _camera.Update(_player);
}
