#include <ui/Screen.h>
#include <game/Game.h>

Game::Game() :
    Race(_raceUpdater),
    _screenManager(InputDevices, _trackManager, Race)
{
}

void Game::Init()
{
    _renderManager.Init();
    _voxManager.Init();
}

void Game::Update()
{
    InputDevices.Keyboard.Update();
    _screenManager.GetCurrentScreen().Update();
    _screenManager.GetCurrentScreen().ProcessInput();
}

void Game::RenderCurrentScreen()
{
    Screen& currentScreen = _screenManager.GetCurrentScreen();
    _renderManager.GetScreenRenderer(currentScreen).Render(currentScreen);
}

void Game::VoiceCurrentScreen()
{
    Screen& currentScreen = _screenManager.GetCurrentScreen();
    _voxManager.GetScreenVox(currentScreen).Voice(currentScreen);
}
