#include <core/GameInitializer.h>
#include <core/Game.h>

Game::Game() :
    Track(_trackManager.GetCurrentTrack()),
    _gameUpdater(Player, _trackManager, Camera),
    PlayerController(Player),
    _screenManager(InputDevices, PlayerController, *this)
{
    _isPaused = false;
    _currentGameUpdater = &_gameUpdater;
    GameInitializer initializer;
    initializer.Init(*this);
}

void Game::Update()
{
    _currentGameUpdater->Update();
    InputDevices.Keyboard.Update();
    _screenManager.GetCurrentScreen().ProcessInput();
}

void Game::SwitchPause()
{
    _isPaused = !_isPaused;
    _currentGameUpdater = _isPaused ? (IGameUpdater*)&_emptyGameUpdater : &_gameUpdater;
}

Screen& Game::GetCurrentScreen()
{
    return _screenManager.GetCurrentScreen();
}
