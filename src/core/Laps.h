#pragma once

#include <lib/Object.h>
#include <lib/String.h>
#include <model/Ship.h>
#include <model/Track.h>
#include <core/LapChecker.h>
#include <core/LapTimer.h>

class Laps : public Object
{
    LapChecker _lapChecker;
    LapTimer _lapTimer;
    int _currentLapNumber;

public:
    Laps();

    void StartFirstLap();
    int GetCurrentLapNumber();
    int GetLapsCount();
    void GetCurrentLapTime(String& result);
    void Update(Ship& ship, Track& track);
};
