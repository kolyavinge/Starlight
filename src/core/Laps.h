#pragma once

#include <lib/Object.h>
#include <lib/String.h>
#include <model/Ship.h>
#include <model/Track.h>
#include <core/LapCounter.h>
#include <core/LapTimer.h>

class Laps : public Object
{
    LapCounter _lapCounter;
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
