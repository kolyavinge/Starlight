#pragma once

#include <lib/Object.h>
#include <model/Ship.h>

class ShipMesh : public Object
{
public:
    void Render(Ship& ship);

private:
    void SetPosition(Ship& ship);
    void RenderBody();
    void RenderUpBody();
    void RenderDownBody();
    void RenderCabin();
    void RenderFrontWings();
    void RenderFrontWing();
    void RenderRearWings();
    void RenderRearWing();
    void RenderRearSmallWings();
    void RenderTurbines();
    void RenderTurbine();
    float GetAngleBetweenShipAndYStraight(Ship& ship);
};
