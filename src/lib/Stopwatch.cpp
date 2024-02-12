#include <lib/DateTime.h>
#include <lib/Stopwatch.h>

Stopwatch::Stopwatch()
{
    _elapsedMilliseconds = 0;
    _startTimestamp = 0;
    _lastTimestamp = 0;
    _isActive = false;
}

void Stopwatch::Start()
{
    if (!_isActive)
    {
        _startTimestamp = DateTime::GetCurrentEpochMilliseconds();
        _isActive = true;
    }
}

void Stopwatch::Stop()
{
    if (_isActive)
    {
        CommitElapsed();
        _isActive = false;
    }
}

void Stopwatch::Reset()
{
    _elapsedMilliseconds = 0;
    _startTimestamp = DateTime::GetCurrentEpochMilliseconds();
}

long long Stopwatch::GetElapsedMilliseconds()
{
    return _elapsedMilliseconds;
}

TimeSpan Stopwatch::GetElapsed()
{
    if (_isActive)
    {
        CommitElapsed();
    }

    return TimeSpan(_elapsedMilliseconds);
}

void Stopwatch::CommitElapsed()
{
    _lastTimestamp = DateTime::GetCurrentEpochMilliseconds();
    _elapsedMilliseconds += _lastTimestamp - _startTimestamp;
    _startTimestamp = _lastTimestamp;
}
