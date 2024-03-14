#pragma once

#include <lib/Object.h>
#include <lib/IArray.h>
#include <model/Ship.h>
#include <render/common/ShipMesh.h>

class ShipsRenderer : public Object
{
    ShipMesh _shipMesh;

public:
    void Init();
    void Render(Ship& player, IArray<Ship>& enemies);

private:
    void RenderShip(Ship& ship, int defaultTexture);
};
