#include <lib/DateTime.h>
#include <lib/TimeSpan.h>
#include <lib/NumericConverter.h>
#include <core/LapTimer.h>

LapTimer::LapTimer()
{
    _lastTimestamp = 0;
    _elapsed = 0;
}

void LapTimer::StartNew()
{
    _lastTimestamp = DateTime::GetCurrentEpochMilliseconds();
    _elapsed = 0;
}

void LapTimer::Update()
{
    long long currentTimestamp = DateTime::GetCurrentEpochMilliseconds();
    _elapsed += currentTimestamp - _lastTimestamp;
    _lastTimestamp = currentTimestamp;
}

long long LapTimer::GetElapsedMilliseconds()
{
    return _elapsed;
}

void LapTimer::ToString(String& result)
{
    TimeSpan ts(_elapsed);

    // hours + minutes
    if (ts.GetMinutes() < 10)
    {
        result.Append(L'0');
    }
    NumericConverter::IntToString(60 * ts.GetHours() + ts.GetMinutes(), result);
    result.Append(L':');

    // seconds
    if (ts.GetSeconds() < 10)
    {
        result.Append(L'0');
    }
    NumericConverter::IntToString(ts.GetSeconds(), result);
    result.Append(L':');

    // milliseconds
    if (ts.GetMilliseconds() < 100)
    {
        result.Append(L'0');
    }
    if (ts.GetMilliseconds() < 10)
    {
        result.Append(L'0');
    }
    NumericConverter::IntToString(ts.GetMilliseconds(), result);
}
