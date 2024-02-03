#include <core/Game.h>

Game::Game() :
    Race(_raceUpdater),
    _screenManager(InputDevices, _trackManager, Race)
{
}

void Game::Update()
{
    InputDevices.Keyboard.Update();
    _screenManager.GetCurrentScreen().Update();
    _screenManager.GetCurrentScreen().ProcessInput();
}

Screen& Game::GetCurrentScreen()
{
    return _screenManager.GetCurrentScreen();
}
