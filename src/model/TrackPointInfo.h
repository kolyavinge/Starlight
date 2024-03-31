#pragma once

#include <lib/Object.h>

enum class TrackPointKind { Straight, LeftTurn, RightTurn };

class TrackPointInfo : public Object
{
public:
    TrackPointKind Kind;
    float RemainingDistance;
    float Radius;

    TrackPointInfo();

    bool IsTurn();
};
