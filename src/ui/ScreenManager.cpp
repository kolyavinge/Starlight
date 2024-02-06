#include <ui/ScreenManager.h>

ScreenManager::ScreenManager(
    IScreenNavigator& screenNavigator,
    InputDevices& inputDevices,
    TrackManager& trackManager,
    Race& race) :
    _startMenuScreen(screenNavigator, inputDevices),
    _trackSelectorScreen(screenNavigator, inputDevices, trackManager, race),
    _racePreparationScreen(screenNavigator, inputDevices, race),
    _raceScreen(screenNavigator, inputDevices, race),
    _pauseMenuScreen(screenNavigator, inputDevices, race)
{
    _screens[(int)ScreenKind::StartMenu] = &_startMenuScreen;
    _screens[(int)ScreenKind::TrackSelector] = &_trackSelectorScreen;
    _screens[(int)ScreenKind::RacePreparation] = &_racePreparationScreen;
    _screens[(int)ScreenKind::Race] = &_raceScreen;
    _screens[(int)ScreenKind::PauseMenu] = &_pauseMenuScreen;
    _currentScreen = nullptr;
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
