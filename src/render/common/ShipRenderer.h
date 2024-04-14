#pragma once

#include <lib/Object.h>
#include <lib/di/ResolvingFactory.h>
#include <model/Ship.h>
#include <core/Camera.h>
#include <gl/VBOMeshRenderer.h>
#include <render/mesh/ShipMesh.h>
#include <render/shader/ShaderPrograms.h>

class ShipRenderer : public Object
{
    Camera& _camera;
    ShipMesh& _shipMesh;
    ShaderProgram& _shaderProgram;
    VBOMeshRenderer _vboMeshRenderer;

public:
    ShipRenderer(
        Camera& camera,
        ShipMesh& shipMesh,
        ShaderPrograms& shaderPrograms);

    void Render(Ship& ship, int textureIndex);

private:
    void SetPosition(Ship& ship);
    void RenderAIMovingDirections(Ship& ship);
    void RenderThrottle(Ship& ship);
};

class ShipRendererResolvingFactory : public ResolvingFactory<ShipRenderer>
{
public:
    ShipRenderer* Make(Resolver& resolver) override;
};
