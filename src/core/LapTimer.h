#pragma once

#include <lib/Object.h>
#include <lib/String.h>
#include <lib/Stopwatch.h>

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
