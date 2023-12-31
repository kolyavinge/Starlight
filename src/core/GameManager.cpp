#include <core/GameInitializer.h>
#include <core/GameManager.h>

GameManager GameManager::Instance;

GameManager::GameManager() :
    _player(),
    _gameUpdater(_player, _track, _camera),
    _playerController(_player),
    Game(
        _player,
        _track,
        _gameUpdater,
        _playerController,
        _camera)
{
    GameInitializer initializer;
    initializer.Init(Game);
}
