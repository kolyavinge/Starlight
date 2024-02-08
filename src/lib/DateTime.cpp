#include <chrono>
#include <lib/DateTime.h>

long long DateTime::GetCurrentEpochMilliseconds()
{
    using namespace std::chrono;
    return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}
