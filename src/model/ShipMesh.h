#pragma once

#include "lib/Object.h"
#include "model/Ship.h"

class ShipMesh : public Object
{
public:
    void Render(Ship& ship);
};
