#include <gl/opengl.h>
#include <render/common/RenderConstants.h>
#include <render/common/TrackRenderer.h>

TrackRenderer::TrackRenderer(
    Camera& camera,
    TrackMesh& trackMesh,
    ShaderPrograms& shaderPrograms) :
    _camera(camera),
    _trackMesh(trackMesh),
    _shaderProgram(shaderPrograms.DefaultShaderProgram)
{
}

void TrackRenderer::Init(Track& track)
{
    _groundVBO.Clear();
    _groundMesh.Clear();
    _trackMesh.MakeGroundMesh(track, _groundMesh);
    _groundVBO.Init(_groundMesh);
}

void TrackRenderer::Render()
{
    glEnable(GL_BLEND);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    _shaderProgram.Use();
    _shaderProgram.SetUniform("lightPos", RenderConstants::LightPosition);
    _shaderProgram.SetUniform("cameraPos", _camera.Position);
    _shaderProgram.SetUniform("modelMatrix", _modelMatrix.GetPtr());
    _shaderProgram.SetUniform("alpha", 0.5f);
    _groundVBO.Render();
    _shaderProgram.Unuse();
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_BLEND);
}

void TrackRenderer::RenderEdges(Track& track)
{
    glColor3f(1.0f, 1.0f, 1.0f);

    for (int edgeIndex = 0; edgeIndex < track.EdgesCount; edgeIndex++)
    {
        TrackEdge& outsideEdge = track.OutsideEdges[edgeIndex];
        TrackEdge& outsideNextEdge = track.OutsideEdges[edgeIndex + 1];
        RenderEdge(outsideEdge, outsideNextEdge);

        TrackEdge& insideEdge = track.InsideEdges[edgeIndex];
        TrackEdge& insideNextEdge = track.InsideEdges[edgeIndex + 1];
        RenderEdge(insideEdge, insideNextEdge);
    }
}

void TrackRenderer::RenderEdge(TrackEdge& edge, TrackEdge& nextEdge)
{
    const float textureStep = 1.0f / (float)edge.Points.GetCount();

    for (int pointIndex = 0; pointIndex < edge.Points.GetCount() - 1; pointIndex++)
    {
        const float textureX = (float)pointIndex * textureStep;

        glBegin(GL_QUADS);

        glTexCoord2f(textureX, 0.0f);
        glVertex3f(edge.Points[pointIndex]);

        glTexCoord2f(textureX, 1.0f);
        glVertex3f(nextEdge.Points[pointIndex]);

        glTexCoord2f(textureX + textureStep, 1.0f);
        glVertex3f(nextEdge.Points[pointIndex + 1]);

        glTexCoord2f(textureX + textureStep, 0.0f);
        glVertex3f(edge.Points[pointIndex + 1]);

        glEnd();
    }

    const float textureX = (float)(edge.Points.GetCount() - 1) * textureStep;

    glBegin(GL_QUADS);

    glTexCoord2f(textureX, 0.0f);
    glVertex3f(edge.Points[edge.Points.GetCount() - 1]);

    glTexCoord2f(textureX, 1.0f);
    glVertex3f(nextEdge.Points[edge.Points.GetCount() - 1]);

    glTexCoord2f(textureX + textureStep, 1.0f);
    glVertex3f(nextEdge.Points[0]);

    glTexCoord2f(textureX + textureStep, 0.0f);
    glVertex3f(edge.Points[0]);

    glEnd();
}

TrackRenderer* TrackRendererResolvingFactory::Make(Resolver& resolver)
{
    return new TrackRenderer(
        resolver.Resolve<Camera>(),
        resolver.Resolve<TrackMesh>(),
        resolver.Resolve<ShaderPrograms>());
}
