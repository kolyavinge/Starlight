#pragma once

#include <lib/Object.h>

class Random : public Object
{
public:
    Random();

    int GetInt(int max);
};
