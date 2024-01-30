#include <ui/ScreenManager.h>

ScreenManager::ScreenManager(
    InputDevices& inputDevices,
    ShipController& playerController,
    IGameStarter& gameStarter,
    IPauseSwitcher& pauseSwitcher) :
    _startMenuScreen(*this, inputDevices),
    _trackSelectorScreen(*this, inputDevices, gameStarter),
    _pauseMenuScreen(*this, inputDevices, pauseSwitcher),
    _gameScreen(*this, inputDevices, playerController, pauseSwitcher)
{
    NavigateToStartMenu();
}

Screen& ScreenManager::GetCurrentScreen()
{
    return *_currentScreen;
}

void ScreenManager::NavigateToStartMenu()
{
    _currentScreen = &_startMenuScreen;
    _currentScreen->Activate();
}

void ScreenManager::NavigateToTrackSelector()
{
    _currentScreen = &_trackSelectorScreen;
    _currentScreen->Activate();
}

void ScreenManager::NavigateToPauseMenu()
{
    _currentScreen = &_pauseMenuScreen;
    _currentScreen->Activate();
}

void ScreenManager::NavigateToGame()
{
    _currentScreen = &_gameScreen;
    _currentScreen->Activate();
}
