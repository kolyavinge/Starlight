#pragma once

#include <lib/Object.h>
#include <model/Ship.h>
#include <render/ShipMesh.h>

class ShipRenderer : public Object
{
    ShipMesh _shipMesh;

public:
    void Render(Ship& ship);
};
