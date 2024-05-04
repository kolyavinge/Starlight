#pragma once

#include <lib/Object.h>
#include <lib/di/ResolvingFactory.h>
#include <model/Ship.h>
#include <gl/VBOMeshRenderer.h>
#include <render/mesh/ExhaustMesh.h>
#include <render/shader/ShaderPrograms.h>

class ExhaustRenderer : public Object
{
    int _activeTextureIndex;
    ExhaustMesh& _exhaustMesh;
    ShaderProgram& _shaderProgram;
    VBOMeshRenderer _vboMeshRenderer;

public:
    ExhaustRenderer(
        ExhaustMesh& exhaustMesh,
        ShaderPrograms& shaderPrograms);

    void Update();
    void Render(Ship& ship);
};

class ExhaustMeshRendererResolvingFactory : public ResolvingFactory<ExhaustRenderer>
{
public:
    ExhaustRenderer* Make(Resolver& resolver) override;
};
