#pragma once

#include <lib/Object.h>
#include <lib/Array.h>
#include <core/TrackManager.h>
#include <core/Race.h>
#include <input/InputDevices.h>
#include <ui/IScreenNavigator.h>
#include <ui/Screen.h>
#include <ui/StartMenuScreen.h>
#include <ui/TrackSelectorScreen.h>
#include <ui/RacePreparationScreen.h>
#include <ui/RaceScreen.h>
#include <ui/PauseMenuScreen.h>
#include <ui/FinishScreen.h>

class ScreenManager : public Object
{
    StartMenuScreen _startMenuScreen;
    TrackSelectorScreen _trackSelectorScreen;
    RacePreparationScreen _racePreparationScreen;
    RaceScreen _raceScreen;
    PauseMenuScreen _pauseMenuScreen;
    FinishScreen _finishScreen;
    Array<Screen*, 6> _screens;
    Screen* _currentScreen;

public:
    ScreenManager(
        IScreenNavigator& screenNavigator,
        InputDevices& inputDevices,
        TrackManager& trackManager,
        Race& race);

    Screen& GetScreen(ScreenKind kind);
    Screen& GetCurrentScreen();
    void SetCurrentScreen(Screen& screen);
};
