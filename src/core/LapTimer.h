#pragma once

#include <lib/Object.h>
#include <lib/String.h>
#include <lib/Stopwatch.h>
#include <lib/di/ResolvingFactory.h>

class LapTimer : public Object
{
    Stopwatch _stopwatch;

public:
    void Start();
    void Stop();
    void Reset();
    long long GetElapsedMilliseconds();
    void ToString(String& result);
};

class LapTimerResolvingFactory : public ResolvingFactory<LapTimer>
{
public:
    LapTimer* Make(Resolver& resolver) override;
};
