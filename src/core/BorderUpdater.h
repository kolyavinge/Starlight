#pragma once

#include "lib/Object.h"
#include "model/Ship.h"

class BorderUpdater : public Object
{
public:
    void Update(Ship& ship);
};
