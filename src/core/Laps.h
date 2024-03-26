#pragma once

#include <lib/Object.h>
#include <lib/String.h>
#include <lib/List.h>
#include <lib/di/ResolvingFactory.h>
#include <model/Ship.h>
#include <model/Track.h>
#include <core/RaceState.h>
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
    bool IsLapCompleted;

    Laps();

    void StartFirstLap();
    void StopTimer();
    void ResumeTimer();
    int GetCurrentLapNumber();
    int GetLapsCount();
    void GetCurrentLapTime(String& result);
    int GetCompleteLapsCount();
    void GetCompletedLapTime(int completeLapNumber, String& result);
    bool IsLastLap();
    void Update(RaceState& state, Ship& ship, Track& track);
};

class LapsResolvingFactory : public ResolvingFactory<Laps>
{
public:
    Laps* Make(Resolver& resolver) override;
};
