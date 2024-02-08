#pragma once

#include <lib/Object.h>
#include <lib/TimeSpan.h>

class Stopwatch : public Object
{
    long long _elapsedMilliseconds;
    long long _startTimestamp;
    long long _lastTimestamp;
    bool _isActive;

public:
    Stopwatch();

    void Start();
    void Stop();
    void Reset();
    TimeSpan GetElapsed();

private:
    void CommitElapsed();
    long long GetCurrentMilliseconds();
};
