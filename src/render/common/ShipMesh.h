#pragma once

#include <lib/Object.h>
#include <model/Ship.h>
#include <gl/Mesh.h>
#include <gl/VBOMeshRenderer.h>

class ShipMesh : public Object
{
    Mesh _shipMesh;
    VBOMeshRenderer _vboMeshRenderer;

public:
    void Init();
    void Render(Ship& ship, int textureIndex);
    int GetTexturesCount();

private:
    void SetPosition(Ship& ship);
};
