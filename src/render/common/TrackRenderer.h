#pragma once

#include <lib/Object.h>
#include <lib/di/ResolvingFactory.h>
#include <calc/Matrix4.h>
#include <model/Track.h>
#include <core/Camera.h>
#include <gl/Mesh.h>
#include <gl/ShaderProgram.h>
#include <gl/VBOMeshRenderer.h>
#include <render/mesh/TrackMesh.h>
#include <render/shader/ShaderPrograms.h>
#include <render/sm/ShadowMaps.h>

class TrackRenderer : public Object
{
    Matrix4 _modelMatrix;
    Camera& _camera;
    TrackMesh& _trackMesh;
    ShaderProgram& _mainProgram;
    ShaderProgram& _withoutShadowsProgram;
    ShaderProgram& _vertexOnlyProgram;
    ShadowMaps& _shadowMaps;
    Mesh _groundMesh;
    Mesh _edgeMesh;
    VBOMeshRenderer _groundVBO;
    VBOMeshRenderer _edgeVBO;

public:
    TrackRenderer(
        Camera& camera,
        TrackMesh& trackMesh,
        ShaderPrograms& shaderPrograms,
        ShadowMaps& shadowMaps);

    void Init(Track& track);
    void Render();
    void RenderWithoutShadows();
    void FillDepthBufferForShadow();

private:
    void RenderEdgeNormals(Track& track);
};

class TrackRendererResolvingFactory : public ResolvingFactory<TrackRenderer>
{
public:
    TrackRenderer* Make(Resolver& resolver) override;
};
