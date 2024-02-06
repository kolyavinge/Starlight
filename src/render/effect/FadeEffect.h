#pragma once

#include <lib/Object.h>

enum class FadeDirection
{
    ToTransparent,
    ToBlack
};

class FadeEffect : public Object
{
    FadeDirection _direction;
    int _iterationsCount;
    int _currentIteration;
    float _step;
    float _alpha;

public:
    FadeEffect(FadeDirection direction, int iterationsCount);

    bool IsActive();
    void Activate();
    bool IsCompleted();
    void Reset();
    void Render();
};
