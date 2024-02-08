#include <lib/TimeSpan.h>

TimeSpan::TimeSpan()
{
    _milliseconds = 0;
    _seconds = 0;
    _minutes = 0;
    _hours = 0;
}

TimeSpan::TimeSpan(long long totalMilliseconds)
{
    InitFromMilliseconds(totalMilliseconds);
}

int TimeSpan::GetHours()
{
    return _hours;
}

int TimeSpan::GetMinutes()
{
    return _minutes;
}

int TimeSpan::GetSeconds()
{
    return _seconds;
}

int TimeSpan::GetMilliseconds()
{
    return _milliseconds;
}

void TimeSpan::InitFromMilliseconds(long long totalMilliseconds)
{
    _milliseconds = totalMilliseconds % 1000;
    _seconds = (totalMilliseconds / 1000) % 60;
    _minutes = (totalMilliseconds / (60 * 1000)) % 60;
    _hours = (totalMilliseconds / (60 * 60 * 1000)) % 60;
}
