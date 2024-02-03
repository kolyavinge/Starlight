#include <ui/ScreenManager.h>

ScreenManager::ScreenManager(
    InputDevices& inputDevices,
    TrackManager& trackManager,
    Race& race) :
    _startMenuScreen(*this, inputDevices),
    _trackSelectorScreen(*this, inputDevices, trackManager, race),
    _pauseMenuScreen(*this, inputDevices, race),
    _gameScreen(*this, inputDevices, race)
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
