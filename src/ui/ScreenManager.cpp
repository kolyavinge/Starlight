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
    _screens[(int)ScreenKind::StartMenu] = &_startMenuScreen;
    _screens[(int)ScreenKind::TrackSelector] = &_trackSelectorScreen;
    _screens[(int)ScreenKind::RacePreparation] = &_racePreparationScreen;
    _screens[(int)ScreenKind::Race] = &_raceScreen;
    _screens[(int)ScreenKind::PauseMenu] = &_pauseMenuScreen;
    NavigateToStartMenu();
}

Screen& ScreenManager::GetScreen(ScreenKind kind)
{
    return *_screens[(int)kind];
}

Screen& ScreenManager::GetCurrentScreen()
{
    return *_currentScreen;
}

void ScreenManager::SetCurrentScreen(Screen& screen)
{
    _currentScreen = &screen;
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
