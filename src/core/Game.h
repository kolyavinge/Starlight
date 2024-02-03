#pragma once

#include <lib/Object.h>
#include <core/TrackManager.h>
#include <core/Race.h>
#include <input/InputDevices.h>
#include <ui/Screen.h>
#include <ui/ScreenManager.h>

class Game : public Object
{
    TrackManager _trackManager;
    RaceUpdater _raceUpdater;
    ScreenManager _screenManager;

public:
    Race Race;
    InputDevices InputDevices;

    Game();

    void Update();
    Screen& GetCurrentScreen();
};
