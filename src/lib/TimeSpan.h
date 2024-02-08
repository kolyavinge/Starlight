#pragma once

#include <lib/Object.h>

class TimeSpan : public Object
{
    int _hours;
    int _minutes;
    int _seconds;
    int _milliseconds;

public:
    TimeSpan();
    TimeSpan(long long totalMilliseconds);

    int GetHours();
    int GetMinutes();
    int GetSeconds();
    int GetMilliseconds();

    void InitFromMilliseconds(long long totalMilliseconds);
};
