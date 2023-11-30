#include "core/GameInitializer.h"
#include "core/GameManager.h"

GameManager GameManager::Instance;

GameManager::GameManager() :
    _player(),
    _moveLogic(),
    _gameUpdater(_player, _velocityCalculator, _moveLogic, _collisionDetector),
    _playerController(_player),
    Game(_gameUpdater, _playerController)
{
    GameInitializer initializer;
    initializer.Init(Game);
}
