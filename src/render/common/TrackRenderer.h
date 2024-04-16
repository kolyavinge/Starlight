#pragma once

#include <lib/Object.h>
#include <lib/di/ResolvingFactory.h>
#include <calc/ModelMatrix.h>
#include <model/Track.h>
#include <model/TrackEdge.h>
#include <core/Camera.h>
#include <gl/Mesh.h>
#include <gl/ShaderProgram.h>
#include <gl/VBOMeshRenderer.h>
#include <render/mesh/TrackMesh.h>
#include <render/shader/ShaderPrograms.h>

class TrackRenderer : public Object
{
    ModelMatrix _modelMatrix;
    Camera& _camera;
    TrackMesh& _trackMesh;
    ShaderProgram& _shaderProgram;
    Mesh _groundMesh;
    VBOMeshRenderer _groundVBO;

public:
    TrackRenderer(
        Camera& camera,
        TrackMesh& trackMesh,
        ShaderPrograms& shaderPrograms);

    void Init(Track& track);
    void Render();

private:
    void RenderEdges(Track& track);
    void RenderEdge(TrackEdge& edge, TrackEdge& nextEdge);
};

class TrackRendererResolvingFactory : public ResolvingFactory<TrackRenderer>
{
public:
    TrackRenderer* Make(Resolver& resolver) override;
};
