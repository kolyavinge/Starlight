#pragma once

#include <lib/Object.h>
#include <core/TrackManager.h>
#include <core/Race.h>
#include <input/InputDevices.h>
#include <ui/StartMenuScreen.h>
#include <ui/TrackSelectorScreen.h>
#include <ui/PauseMenuScreen.h>
#include <ui/RaceScreen.h>
#include <ui/IScreenNavigator.h>

class ScreenManager : public Object, public IScreenNavigator
{
    StartMenuScreen _startMenuScreen;
    TrackSelectorScreen _trackSelectorScreen;
    PauseMenuScreen _pauseMenuScreen;
    RaceScreen _raceScreen;
    Screen* _currentScreen;

public:
    ScreenManager(
        InputDevices& inputDevices,
        TrackManager& trackManager,
        Race& race);

    Screen& GetCurrentScreen();

    void NavigateToStartMenu() override;
    void NavigateToTrackSelector() override;
    void NavigateToPauseMenu() override;
    void NavigateToRace() override;
};
