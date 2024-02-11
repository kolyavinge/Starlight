#pragma once

#include <lib/Object.h>
#include <lib/String.h>
#include <lib/List.h>
#include <model/Ship.h>
#include <model/Track.h>
#include <core/LapChecker.h>
#include <core/LapTimer.h>

struct CompleteLap
{
    long long TimeMilliseconds = 0;
    String TimeString;
};

class Laps : public Object
{
    LapChecker _lapChecker;
    LapTimer _lapTimer;
    int _currentLapNumber;
    List<CompleteLap> _completeLaps;

public:
    Laps();

    void StartFirstLap();
    int GetCurrentLapNumber();
    int GetLapsCount();
    void GetCurrentLapTime(String& result);
    void GetCompletedLapTime(int lapNumber, String& result);
    void Update(Ship& ship, Track& track);
};
