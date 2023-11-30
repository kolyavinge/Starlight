#include "core/GameUpdater.h"

GameUpdater::GameUpdater(
    Ship& player,
    VelocityCalculator& velocityCalculator,
    MoveLogic& moveLogic,
    CollisionDetector& collisionDetector) :
    _player(player),
    _velocityCalculator(velocityCalculator),
    _moveLogic(moveLogic),
    _collisionDetector(collisionDetector)
{
}

void GameUpdater::Update()
{
    _velocityCalculator.CalculateVelocity(_player);
    _moveLogic.Move(_player);
    _collisionDetector.Detect(_player);
}
