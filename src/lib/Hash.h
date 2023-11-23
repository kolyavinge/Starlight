#pragma once

#include "lib/Object.h"

class Hash : public Object
{
    int _result;

public:
    Hash();
    void Add(int value);
    void Add(float value);
    void Add(double value);
    int GetResult();
};
