#pragma once

#include "lib/Object.h"
#include "model/Ship.h"

class DebugShipRenderer : public Object
{
public:
    void Render(Ship& ship);
};
