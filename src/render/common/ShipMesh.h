#pragma once

#include <lib/Object.h>
#include <model/Ship.h>
#include <gl/Mesh.h>
#include <gl/SimpleMeshRenderer.h>

class ShipMesh : public Object
{
    Mesh _shipMesh;
    SimpleMeshRenderer _shipMeshRenderer;

public:
    void Init();
    void Render(Ship& ship, int textureIndex);

private:
    void SetPosition(Ship& ship);
};
