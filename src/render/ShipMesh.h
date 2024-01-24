#pragma once

#include <lib/Object.h>
#include <calc/Vector3.h>
#include <model/Ship.h>
#include <gl/Mesh.h>

class ShipMesh : public Object
{
    Mesh _shipMesh;
    Vector3 _scaleVector;

public:
    void Init();
    void Render(Ship& ship);

private:
    void SetPosition(Ship& ship);
};
