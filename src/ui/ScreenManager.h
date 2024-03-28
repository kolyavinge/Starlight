#pragma once

#include <lib/Object.h>
#include <lib/Array.h>
#include <lib/di/ResolvingFactory.h>
#include <ui/Screen.h>
#include <ui/StartMenuScreen.h>
#include <ui/TrackSelectorScreen.h>
#include <ui/RacePreparationScreen.h>
#include <ui/RaceScreen.h>
#include <ui/PauseMenuScreen.h>
#include <ui/FinishScreen.h>

class ScreenManager : public Object
{
    StartMenuScreen& _startMenuScreen;
    TrackSelectorScreen& _trackSelectorScreen;
    RacePreparationScreen& _racePreparationScreen;
    RaceScreen& _raceScreen;
    PauseMenuScreen& _pauseMenuScreen;
    FinishScreen& _finishScreen;
    Array<Screen*, 6> _screens;
    Screen* _currentScreen;

public:
    ScreenManager(
        StartMenuScreen& startMenuScreen,
        TrackSelectorScreen& trackSelectorScreen,
        RacePreparationScreen& racePreparationScreen,
        RaceScreen& raceScreen,
        PauseMenuScreen& pauseMenuScreen,
        FinishScreen& finishScreen);

    Screen& GetScreen(ScreenKind kind);
    Screen& GetCurrentScreen();
    void SetCurrentScreen(Screen& screen);
};

class ScreenManagerResolvingFactory : public ResolvingFactory<ScreenManager>
{
public:
    ScreenManager* Make(Resolver& resolver) override;
};
