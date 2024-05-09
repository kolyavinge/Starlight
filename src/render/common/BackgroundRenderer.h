#pragma once

#include <lib/Object.h>
#include <lib/di/ResolvingFactory.h>
#include <gl/ShaderProgram.h>
#include <gl/VBOMeshRenderer.h>
#include <render/mesh/BackgroundSphereMesh.h>
#include <render/shader/ShaderPrograms.h>

class BackgroundRenderer : public Object
{
    ShaderProgram& _shaderProgram;
    VBOMeshRenderer _vboMeshRenderer;

public:
    BackgroundRenderer(
        BackgroundSphereMesh& backgroundSphereMesh,
        ShaderPrograms& shaderPrograms);

    void Render();
};

class BackgroundRendererResolvingFactory : public ResolvingFactory<BackgroundRenderer>
{
public:
    BackgroundRenderer* Make(Resolver& resolver) override;
};
