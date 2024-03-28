#include <ui/ScreenManager.h>

ScreenManager::ScreenManager(
    StartMenuScreen& startMenuScreen,
    TrackSelectorScreen& trackSelectorScreen,
    RacePreparationScreen& racePreparationScreen,
    RaceScreen& raceScreen,
    PauseMenuScreen& pauseMenuScreen,
    FinishScreen& finishScreen) :
    _startMenuScreen(startMenuScreen),
    _trackSelectorScreen(trackSelectorScreen),
    _racePreparationScreen(racePreparationScreen),
    _raceScreen(raceScreen),
    _pauseMenuScreen(pauseMenuScreen),
    _finishScreen(finishScreen)
{
    _screens[(int)ScreenKind::StartMenu] = &_startMenuScreen;
    _screens[(int)ScreenKind::TrackSelector] = &_trackSelectorScreen;
    _screens[(int)ScreenKind::RacePreparation] = &_racePreparationScreen;
    _screens[(int)ScreenKind::Race] = &_raceScreen;
    _screens[(int)ScreenKind::PauseMenu] = &_pauseMenuScreen;
    _screens[(int)ScreenKind::Finish] = &_finishScreen;
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

ScreenManager* ScreenManagerResolvingFactory::Make(Resolver& resolver)
{
    return new ScreenManager(
        resolver.Resolve<StartMenuScreen>(),
        resolver.Resolve<TrackSelectorScreen>(),
        resolver.Resolve<RacePreparationScreen>(),
        resolver.Resolve<RaceScreen>(),
        resolver.Resolve<PauseMenuScreen>(),
        resolver.Resolve<FinishScreen>());
}
