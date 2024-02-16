#include <core/Laps.h>

Laps::Laps()
{
    _currentLapNumber = 0;
}

void Laps::StartFirstLap()
{
    _currentLapNumber = 1;
    _lapChecker.Init();
    _lapTimer.Reset();
    _lapTimer.Start();
    _completeLaps.Clear();
}

void Laps::StopTimer()
{
    _lapTimer.Stop();
}

void Laps::ResumeTimer()
{
    _lapTimer.Start();
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

int Laps::GetCompleteLapsCount()
{
    return _completeLaps.Count();
}

void Laps::GetCompletedLapTime(int completeLapNumber, String& result)
{
    result.Append(_completeLaps[completeLapNumber - 1].TimeString);
}

bool Laps::IsLastLap()
{
    return GetCompleteLapsCount() == GetLapsCount() - 1;
}

void Laps::Update(RaceState& state, Ship& ship, Track& track)
{
    if (_lapChecker.IsLapCompleted(ship, track))
    {
        CompleteLap completeLap;
        completeLap.TimeMilliseconds = _lapTimer.GetElapsedMilliseconds();
        _lapTimer.ToString(completeLap.TimeString);
        _completeLaps.Add(completeLap);
        if (_currentLapNumber < GetLapsCount())
        {
            _currentLapNumber++;
            _lapTimer.Reset();
        }
        else
        {
            state = RaceState::Finish;
            _lapTimer.Stop();
        }
    }
}
