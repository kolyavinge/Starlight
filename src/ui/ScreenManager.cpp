#include <ui/ScreenManager.h>

ScreenManager::ScreenManager(
    InputDevices& inputDevices,
    ShipController& playerController,
    IPauseSwitcher& pauseSwitcher) :
    _startMenuScreen(*this, inputDevices),
    _trackSelectorScreen(*this, inputDevices),
    _pauseMenuScreen(*this, inputDevices),
    _gameScreen(*this, inputDevices, playerController, pauseSwitcher)
{
    NavigateToStartMenu();
    //NavigateToGame();
}

Screen& ScreenManager::GetCurrentScreen()
{
    return *_currentScreen;
}

void ScreenManager::NavigateToStartMenu()
{
    _currentScreen = &_startMenuScreen;
}

void ScreenManager::NavigateToTrackSelector()
{
    _currentScreen = &_trackSelectorScreen;
}

void ScreenManager::NavigateToPauseMenu()
{
    _currentScreen = &_pauseMenuScreen;
}

void ScreenManager::NavigateToGame()
{
    _currentScreen = &_gameScreen;
}
