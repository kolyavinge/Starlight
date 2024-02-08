#pragma once

#include <lib/Object.h>

class DateTime : public Object
{
public:
    static long long GetCurrentEpochMilliseconds();
};
