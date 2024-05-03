#pragma once

#include <lib/Object.h>
#include <lib/di/ResolvingFactory.h>
#include <gl/VBOMeshRenderer.h>
#include <render/mesh/ExhaustMesh.h>
#include <render/shader/ShaderPrograms.h>

class ExhaustMeshRenderer : public Object
{
    int _activeTextureIndex;
    ExhaustMesh& _exhaustMesh;
    ShaderProgram& _shaderProgram;
    VBOMeshRenderer _vboMeshRenderer;

public:
    ExhaustMeshRenderer(
        ExhaustMesh& exhaustMesh,
        ShaderPrograms& shaderPrograms);

    void Update();
    void Render();
};

class ExhaustMeshRendererResolvingFactory : public ResolvingFactory<ExhaustMeshRenderer>
{
public:
    ExhaustMeshRenderer* Make(Resolver& resolver) override;
};
