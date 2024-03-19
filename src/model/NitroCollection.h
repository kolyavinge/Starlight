#pragma once

#include <lib/Object.h>

class NitroCollection : public Object
{
    int _count;

public:
    inline static const int MaxCount = 3;

    NitroCollection();

    void Init();
    void AddOne();
    bool IsFull();
    int GetCount();
};
