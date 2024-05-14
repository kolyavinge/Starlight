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
    _mainProgram(shaderPrograms.MainShaderProgram),
    _withoutShadowsProgram(shaderPrograms.MainWithoutShadowsShaderProgram),
    _vertexOnlyProgram(shaderPrograms.VertexOnlyShaderProgram),
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

    _mainProgram.Use();
    _mainProgram.SetUniform("lightPos", RenderConstants::GlobalLightPosition);
    _mainProgram.SetUniform("cameraPos", _camera.Position);
    _mainProgram.SetUniform("modelMatrix", _modelMatrix.GetPtr());
    _mainProgram.SetUniform("alpha", 0.6f);
    _mainProgram.SetUniform("shadowMatrix1", _shadowMaps.ShipShadowMaps[0].ShadowMatrix.GetPtr());
    _mainProgram.SetUniform("shadowMatrix2", _shadowMaps.ShipShadowMaps[1].ShadowMatrix.GetPtr());
    _mainProgram.SetUniform("shadowMatrix3", _shadowMaps.ShipShadowMaps[2].ShadowMatrix.GetPtr());
    _mainProgram.SetUniform("shadowMatrix4", _shadowMaps.ShipShadowMaps[3].ShadowMatrix.GetPtr());
    _mainProgram.SetUniform("shadowMatrix5", _shadowMaps.TrackShadowMap.ShadowMatrix.GetPtr());

    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, _shadowMaps.ShipShadowMaps[0].TextureId);
    glActiveTexture(GL_TEXTURE2);
    glBindTexture(GL_TEXTURE_2D, _shadowMaps.ShipShadowMaps[1].TextureId);
    glActiveTexture(GL_TEXTURE3);
    glBindTexture(GL_TEXTURE_2D, _shadowMaps.ShipShadowMaps[2].TextureId);
    glActiveTexture(GL_TEXTURE4);
    glBindTexture(GL_TEXTURE_2D, _shadowMaps.ShipShadowMaps[3].TextureId);
    glActiveTexture(GL_TEXTURE5);
    glBindTexture(GL_TEXTURE_2D, _shadowMaps.TrackShadowMap.TextureId);

    glEnable(GL_MULTISAMPLE);
    glEnable(GL_BLEND);
    _groundVBO.Render();
    glDisable(GL_BLEND);
    glDisable(GL_MULTISAMPLE);

    _edgeVBO.Render();

    _mainProgram.Unuse();

    glDisable(GL_TEXTURE_2D);
    glDisable(GL_DEPTH_TEST);
}

void TrackRenderer::RenderWithoutShadows()
{
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);

    _withoutShadowsProgram.Use();
    _withoutShadowsProgram.SetUniform("lightPos", RenderConstants::GlobalLightPosition);
    _withoutShadowsProgram.SetUniform("cameraPos", _camera.Position);
    _withoutShadowsProgram.SetUniform("modelMatrix", _modelMatrix.GetPtr());
    _withoutShadowsProgram.SetUniform("alpha", 0.6f);

    glEnable(GL_MULTISAMPLE);
    glEnable(GL_BLEND);
    _groundVBO.Render();
    glDisable(GL_BLEND);
    glDisable(GL_MULTISAMPLE);

    _edgeVBO.Render();

    _withoutShadowsProgram.Unuse();

    glDisable(GL_TEXTURE_2D);
    glDisable(GL_DEPTH_TEST);
}

void TrackRenderer::FillDepthBufferForShadow()
{
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_POLYGON_OFFSET_FILL);
    glPolygonOffset(2.5f, 5.0f);
    _vertexOnlyProgram.Use();
    _groundVBO.Render();
    _vertexOnlyProgram.Unuse();
    glDisable(GL_POLYGON_OFFSET_FILL);
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
