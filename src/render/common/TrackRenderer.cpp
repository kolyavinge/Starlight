#include <gl/opengl.h>
#include <render/common/RenderConstants.h>
#include <render/common/TrackRenderer.h>

TrackRenderer::TrackRenderer(
    Camera& camera,
    TrackMesh& trackMesh,
    ShaderPrograms& shaderPrograms,
    ShadowMaps& shadowMaps) :
    _camera(camera),
    _trackMesh(trackMesh),
    _shaderProgram(shaderPrograms.DefaultShaderProgram),
    _shadowMaps(shadowMaps)
{
}

void TrackRenderer::Init(Track& track)
{
    _groundVBO.Clear();
    _edgeVBO.Clear();
    _groundMesh.Clear();
    _edgeMesh.Clear();
    _trackMesh.MakeGroundMesh(track, _groundMesh);
    _trackMesh.MakeEdgeMesh(track, _edgeMesh);
    _groundVBO.Init(_groundMesh);
    _edgeVBO.Init(_edgeMesh);
}

void TrackRenderer::Render()
{
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);

    _shaderProgram.Use();
    _shaderProgram.SetUniform("lightPos", RenderConstants::GlobalLightPosition);
    _shaderProgram.SetUniform("cameraPos", _camera.Position);
    _shaderProgram.SetUniform("modelMatrix", _modelMatrix.GetPtr());
    _shaderProgram.SetUniform("alpha", 0.6f);
    //_shaderProgram.SetUniform("shadowMatrix", _shadowMaps.ShipShadowMap.ShadowMatrix);

    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, _shadowMaps.ShipShadowMap.TextureId);

    glEnable(GL_MULTISAMPLE);
    glEnable(GL_BLEND);
    _groundVBO.Render();
    glDisable(GL_BLEND);
    glDisable(GL_MULTISAMPLE);

    _edgeVBO.Render();

    _shaderProgram.Unuse();

    glDisable(GL_TEXTURE_2D);
    glDisable(GL_DEPTH_TEST);
}

void TrackRenderer::RenderEdgeNormals(Track& track)
{
    glColor3f(1.0f, 1.0f, 1.0f);

    for (int edgeIndex = 0; edgeIndex < track.EdgesCount; edgeIndex++)
    {
        for (int pointIndex = 0; pointIndex < track.EdgeNormals[edgeIndex].Points.GetCount(); pointIndex++)
        {
            glPushMatrix();
            glTranslatef(track.InsideEdges[edgeIndex].Points[pointIndex]);
            glBegin(GL_LINES);
            glVertex3f(0, 0, 0);
            glVertex3f(track.EdgeNormals[edgeIndex].Points[pointIndex]);
            glEnd();
            glPopMatrix();
        }
    }
}

TrackRenderer* TrackRendererResolvingFactory::Make(Resolver& resolver)
{
    return new TrackRenderer(
        resolver.Resolve<Camera>(),
        resolver.Resolve<TrackMesh>(),
        resolver.Resolve<ShaderPrograms>(),
        resolver.Resolve<ShadowMaps>());
}
