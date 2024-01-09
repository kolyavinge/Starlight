#pragma once

#include <lib/Object.h>

class HashCode : public Object
{
    int _result;

public:
    HashCode();

    void Add(char value);
    void Add(wchar_t value);
    void Add(int value);
    void Add(float value);
    void Add(double value);
    int GetResult();
};
