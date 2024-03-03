#pragma once

#include <lib/Object.h>
#include <model/Ship.h>

class ShipCollisionResult : public Object
{
public:
    Ship* Ship1;
    Ship* Ship2;

    ShipCollisionResult();

    void Init();
};
