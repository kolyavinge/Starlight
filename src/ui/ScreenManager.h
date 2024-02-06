#pragma once

#include <lib/Object.h>
#include <lib/Array.h>
#include <core/TrackManager.h>
#include <core/Race.h>
#include <input/InputDevices.h>
#include <ui/Screen.h>
#include <ui/IScreenNavigator.h>
#include <ui/StartMenuScreen.h>
#include <ui/TrackSelectorScreen.h>
#include <ui/PauseMenuScreen.h>
#include <ui/RacePreparationScreen.h>
#include <ui/RaceScreen.h>

class ScreenManager : public Object, IScreenNavigator
{
    StartMenuScreen _startMenuScreen;
    TrackSelectorScreen _trackSelectorScreen;
    PauseMenuScreen _pauseMenuScreen;
    RacePreparationScreen _racePreparationScreen;
    RaceScreen _raceScreen;
    Array<Screen*, 5> _screens;
    Screen* _currentScreen;

public:
    ScreenManager(
        InputDevices& inputDevices,
        TrackManager& trackManager,
        Race& race);

    Screen& GetScreen(ScreenKind kind);
    Screen& GetCurrentScreen();
    void SetCurrentScreen(Screen& screen);

    void NavigateToStartMenu() override;
    void NavigateToTrackSelector() override;
    void NavigateToRacePreparation() override;
    void NavigateToRace() override;
    void NavigateToPauseMenu() override;
};
