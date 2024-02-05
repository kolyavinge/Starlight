#include <ui/ScreenManager.h>

ScreenManager::ScreenManager(
    InputDevices& inputDevices,
    TrackManager& trackManager,
    Race& race) :
    _startMenuScreen(*this, inputDevices),
    _trackSelectorScreen(*this, inputDevices, trackManager, race),
    _racePreparationScreen(*this, inputDevices, race),
    _raceScreen(*this, inputDevices, race),
    _pauseMenuScreen(*this, inputDevices, race)
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

void ScreenManager::NavigateToRacePreparation()
{
    _currentScreen = &_racePreparationScreen;
    _currentScreen->Activate();
}

void ScreenManager::NavigateToRace()
{
    _currentScreen = &_raceScreen;
    _currentScreen->Activate();
}

void ScreenManager::NavigateToPauseMenu()
{
    _currentScreen = &_pauseMenuScreen;
    _currentScreen->Activate();
}
