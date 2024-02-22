#pragma once

#include <lib/Object.h>
#include <calc/Vector3.h>
#include <model/Ship.h>
#include <gl/Mesh.h>
#include <gl/SimpleMeshRenderer.h>

class ShipMesh : public Object
{
    Mesh _shipMesh;
    SimpleMeshRenderer _shipMeshRenderer;
    Vector3 _scaleVector;

public:
    void Init();
    void Render(Ship& ship, int textureIndex);

private:
    void SetPosition(Ship& ship);
};
