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
    NavigateTo(ScreenKind::StartMenu);
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

void ScreenManager::NavigateTo(ScreenKind kind)
{
    _currentScreen = _screens[(int)kind];
    _currentScreen->Activate();
}
