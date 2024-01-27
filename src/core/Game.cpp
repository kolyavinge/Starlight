#include <core/GameInitializer.h>
#include <core/Game.h>

Game::Game() :
    Track(_trackManager.GetCurrentTrack()),
    _gameUpdater(Player, _trackManager, Camera),
    PlayerController(Player)
{
    _isPaused = false;
    _currentGameUpdater = &_gameUpdater;
    GameInitializer initializer;
    initializer.Init(*this);
}

void Game::Update()
{
    _currentGameUpdater->Update();
}

void Game::SwitchPause()
{
    _isPaused = !_isPaused;
    _currentGameUpdater = _isPaused ? (IGameUpdater*)&_emptyGameUpdater : &_gameUpdater;
}
