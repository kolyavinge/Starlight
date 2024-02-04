#pragma once

#include <lib/Object.h>

enum class FadeDirection
{
    ToTransparent,
    ToBlack
};

class Fade : public Object
{
    FadeDirection _direction;
    int _iterationsCount;
    bool _isActive;
    float _step;
    float _alpha;

public:
    Fade(FadeDirection direction, int iterationsCount);

    bool IsActive();
    void Activate();
    bool IsCompleted();
    void Render();
};
