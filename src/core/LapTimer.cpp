#include <lib/TimeSpan.h>
#include <lib/NumericConverter.h>
#include <core/LapTimer.h>

void LapTimer::Start()
{
    _stopwatch.Start();
}

void LapTimer::Stop()
{
    _stopwatch.Stop();
}

void LapTimer::Reset()
{
    _stopwatch.Reset();
}

long long LapTimer::GetElapsedMilliseconds()
{
    return _stopwatch.GetElapsedMilliseconds();
}

void LapTimer::ToString(String& result)
{
    TimeSpan ts = _stopwatch.GetElapsed();

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
