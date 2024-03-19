#pragma once

#include <lib/Object.h>
#include <model/Ship.h>

class NitroLogic : public Object
{
public:
    void ProcessNitro(Ship& ship);
};
