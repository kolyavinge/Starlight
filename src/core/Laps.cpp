#include <core/Laps.h>

Laps::Laps(LapChecker& lapChecker, LapTimer& lapTimer) :
    _lapChecker(lapChecker),
    _lapTimer(lapTimer)
{
    _currentLapNumber = 0;
    IsLapCompleted = false;
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
    return 7;
}

void Laps::GetCurrentLapTime(String& result)
{
    _lapTimer.ToString(result);
}

int Laps::GetCompleteLapsCount()
{
    return _completeLaps.GetCount();
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
    IsLapCompleted = false;
    if (_lapChecker.IsLapCompleted(ship, track))
    {
        CompleteLap completeLap;
        completeLap.TimeMilliseconds = _lapTimer.GetElapsedMilliseconds();
        _lapTimer.ToString(completeLap.TimeString);
        _completeLaps.Add(completeLap);
        IsLapCompleted = true;
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

Laps* LapsResolvingFactory::Make(Resolver& resolver)
{
    return new Laps(
        resolver.Resolve<LapChecker>(),
        resolver.Resolve<LapTimer>());
}
