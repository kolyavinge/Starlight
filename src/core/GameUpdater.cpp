#include "core/GameConstants.h"
#include "core/GameUpdater.h"

GameUpdater::GameUpdater(
    Ship& player,
    TurnAngleCalculator& turnAngleCalculator,
    VelocityCalculator& velocityCalculator,
    MoveLogic& moveLogic,
    CollisionDetector& collisionDetector,
    PositionCorrector& positionCorrector,
    BorderUpdater& borderUpdater,
    GameCamera& camera) :
    _player(player),
    _turnAngleCalculator(turnAngleCalculator),
    _velocityCalculator(velocityCalculator),
    _moveLogic(moveLogic),
    _collisionDetector(collisionDetector),
    _positionCorrector(positionCorrector),
    _borderUpdater(borderUpdater),
    _camera(camera)
{
}

void GameUpdater::Update()
{
    float timeStep = GameConstants::TimeStepMax;
    _turnAngleCalculator.CalculateTurnAngle(_player);
    _velocityCalculator.CalculateVelocity(timeStep, _player);
    _moveLogic.Move(timeStep, _player);
    _collisionDetector.DetectCollisions(_player);
    _positionCorrector.CorrectAfterFloatOperations(_player);
    _borderUpdater.Update(_player);
    _camera.Update(_player);
}
