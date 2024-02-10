#include <core/Laps.h>

Laps::Laps()
{
    _currentLapNumber = 0;
}

void Laps::StartFirstLap()
{
    _currentLapNumber = 1;
    _lapChecker.Init();
    _lapTimer.StartNew();
}

int Laps::GetCurrentLapNumber()
{
    return _currentLapNumber;
}

int Laps::GetLapsCount()
{
    return 5;
}

void Laps::GetCurrentLapTime(String& result)
{
    _lapTimer.ToString(result);
}

void Laps::Update(Ship& ship, Track& track)
{
    _lapTimer.Update();
    if (_lapChecker.IsLapCompleted(ship, track))
    {
        _currentLapNumber++;
        _lapTimer.StartNew();
    }
}
