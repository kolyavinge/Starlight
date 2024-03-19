#pragma once

#include <lib/Object.h>

enum class NitroState { Innactive, Activated, Deactivated };

class NitroCollection : public Object
{
    inline static const int _maxIterations = 50;

    int _count;
    int _iterations;

public:
    inline static const int MaxCount = 3;

    NitroState State;

    NitroCollection();

    void Init();
    void AddOne();
    bool IsFull();
    int GetCount();
    void ActivateOne();
    void Update();
};
