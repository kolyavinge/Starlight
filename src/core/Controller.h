#pragma once

#include <lib/Object.h>
#include <model/Ship.h>

class Controller : public Object
{
    Ship& _ship;

public:
    Controller(Ship& ship);

    void ActivateThrottle();
    void ReleaseThrottle();
    void ActivateBreak();
    void ReleaseBreak();
    void TurnLeft();
    void TurnRight();
    void ReleaseTurn();
};
