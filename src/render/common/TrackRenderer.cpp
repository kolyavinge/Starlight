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
    _mainProgram.Use();
    SetupShaderProgramForMainRender();
    RenderVBO();
    _mainProgram.Unuse();
}

void TrackRenderer::RenderForMirrorView()
{
    _mainProgram.Use();
    SetupShaderProgramForMirrorRender();
    RenderVBO();
    _mainProgram.Unuse();
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

void TrackRenderer::RenderVBO()
{
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_MULTISAMPLE);
    glEnable(GL_BLEND);
    _groundVBO.Render();
    glDisable(GL_BLEND);
    glDisable(GL_MULTISAMPLE);
    _edgeVBO.Render();
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_DEPTH_TEST);
}

void TrackRenderer::SetupShaderProgramForMainRender()
{
    _mainProgram.SetUniform("lightPos", RenderConstants::GlobalLightPosition);
    _mainProgram.SetUniform("cameraPos", _camera.Position);
    _mainProgram.SetUniform("modelMatrix", _modelMatrix.GetPtr());
    _mainProgram.SetUniform("alpha", 0.6f);
    _mainProgram.SetUniform("shadowMatrix1", _shadowMaps.PlayerShipShadowMap.ShadowMatrix.GetPtr());
    _mainProgram.SetUniform("shadowMatrix2", _shadowMaps.EnemyShipShadowMaps[0].ShadowMatrix.GetPtr());
    _mainProgram.SetUniform("shadowMatrix3", _shadowMaps.EnemyShipShadowMaps[1].ShadowMatrix.GetPtr());
    _mainProgram.SetUniform("shadowMatrix4", _shadowMaps.EnemyShipShadowMaps[2].ShadowMatrix.GetPtr());
    _mainProgram.SetUniform("shadowMatrix5", _shadowMaps.TrackShadowMap.ShadowMatrix.GetPtr());

    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, _shadowMaps.PlayerShipShadowMap.TextureId);
    glActiveTexture(GL_TEXTURE2);
    glBindTexture(GL_TEXTURE_2D, _shadowMaps.EnemyShipShadowMaps[0].TextureId);
    glActiveTexture(GL_TEXTURE3);
    glBindTexture(GL_TEXTURE_2D, _shadowMaps.EnemyShipShadowMaps[1].TextureId);
    glActiveTexture(GL_TEXTURE4);
    glBindTexture(GL_TEXTURE_2D, _shadowMaps.EnemyShipShadowMaps[2].TextureId);
    glActiveTexture(GL_TEXTURE5);
    glBindTexture(GL_TEXTURE_2D, _shadowMaps.TrackShadowMap.TextureId);
}

void TrackRenderer::SetupShaderProgramForMirrorRender()
{
    _mainProgram.SetUniform("lightPos", RenderConstants::GlobalLightPosition);
    _mainProgram.SetUniform("cameraPos", _camera.Position);
    _mainProgram.SetUniform("modelMatrix", _modelMatrix.GetPtr());
    _mainProgram.SetUniform("alpha", 0.6f);
    _mainProgram.SetUniform("shadowMatrix1", _shadowMaps.EmptyShadowMap.ShadowMatrix.GetPtr());
    _mainProgram.SetUniform("shadowMatrix2", _shadowMaps.EnemyShipShadowMaps[0].ShadowMatrix.GetPtr());
    _mainProgram.SetUniform("shadowMatrix3", _shadowMaps.EnemyShipShadowMaps[1].ShadowMatrix.GetPtr());
    _mainProgram.SetUniform("shadowMatrix4", _shadowMaps.EnemyShipShadowMaps[2].ShadowMatrix.GetPtr());
    _mainProgram.SetUniform("shadowMatrix5", _shadowMaps.TrackShadowMap.ShadowMatrix.GetPtr());

    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, _shadowMaps.EmptyShadowMap.TextureId);
    glActiveTexture(GL_TEXTURE2);
    glBindTexture(GL_TEXTURE_2D, _shadowMaps.EnemyShipShadowMaps[0].TextureId);
    glActiveTexture(GL_TEXTURE3);
    glBindTexture(GL_TEXTURE_2D, _shadowMaps.EnemyShipShadowMaps[1].TextureId);
    glActiveTexture(GL_TEXTURE4);
    glBindTexture(GL_TEXTURE_2D, _shadowMaps.EnemyShipShadowMaps[2].TextureId);
    glActiveTexture(GL_TEXTURE5);
    glBindTexture(GL_TEXTURE_2D, _shadowMaps.TrackShadowMap.TextureId);
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
