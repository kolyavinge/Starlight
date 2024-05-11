#pragma once

#include <lib/Object.h>
#include <lib/di/ResolvingFactory.h>
#include <model/Ship.h>
#include <core/Camera.h>
#include <gl/VBOMeshRenderer.h>
#include <gl/ShaderProgram.h>
#include <render/mesh/ShipMesh.h>
#include <render/shader/ShaderPrograms.h>
#include <render/sm/ShadowMaps.h>
#include <render/common/ExhaustRenderer.h>

class ShipRenderer : public Object
{
    Camera& _camera;
    ShipMesh& _shipMesh;
    ExhaustRenderer& _exhaustRenderer;
    ShaderProgram& _mainProgram;
    ShaderProgram& _vertexOnlyProgram;
    ShadowMaps& _shadowMaps;
    VBOMeshRenderer _vboMeshRenderer;

public:
    ShipRenderer(
        Camera& camera,
        ShipMesh& shipMesh,
        ExhaustRenderer& exhaustRenderer,
        ShaderPrograms& shaderPrograms,
        ShadowMaps& shadowMaps);

    void Update();
    void Render(Ship& ship, int textureIndex);
    void FillDepthBufferForShadow(Ship& ship);

private:
    void RenderExhaust(Ship& ship);
    void GetRenderDetails(Ship& ship, bool& renderShipEnabled, bool& renderExhaustEnabled, int& textureIndex);
    void SetPosition(Ship& ship);
    void RenderAIMovingDirections(Ship& ship);
    void RenderThrottle(Ship& ship);
};

class ShipRendererResolvingFactory : public ResolvingFactory<ShipRenderer>
{
public:
    ShipRenderer* Make(Resolver& resolver) override;
};
