#pragma once

#include <lib/Object.h>
#include <lib/String.h>

class LapTimer : public Object
{
    long long _lastTimestamp;
    long long _elapsed;

public:
    LapTimer();

    void StartNew();
    void Update();
    long long GetElapsedMilliseconds();
    void ToString(String& result);
};
