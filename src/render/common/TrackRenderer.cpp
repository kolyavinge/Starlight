#include <gl/opengl.h>
#include <render/common/TrackRenderer.h>
#include <anx/GraphicResources.h>

void TrackRenderer::Init()
{
    _groundTexture.Load(GraphicResources::GetTrackGround1TextureFilePath());
    _groundFinishTexture.Load(GraphicResources::GetTrackGroundFinishTextureFilePath());
    //_edgeTexture.Load(GraphicResources::GetTrackEdgeTextureFilePath());
}

void TrackRenderer::Render(Track& track)
{
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    RenderTrack(track);
    RenderEdges(track);
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_DEPTH_TEST);
}

void TrackRenderer::RenderTrack(Track& track)
{
    glEnable(GL_BLEND);

    const int step = 30;
    glColor4f(1.0f, 1.0f, 1.0f, 0.3f);
    _groundTexture.Bind();
    RenderSegment(track, 0, track.StartFinishLineIndex, step);

    glColor4f(1.0f, 1.0f, 1.0f, 0.4f);
    _groundFinishTexture.Bind();
    RenderSegment(track, track.StartFinishLineIndex, track.StartFinishLineIndex + 2 * step, step);

    glColor4f(1.0f, 1.0f, 1.0f, 0.3f);
    _groundTexture.Bind();
    RenderSegment(track, track.StartFinishLineIndex + 2 * step, track.PointsCount, step);

    glDisable(GL_BLEND);
}

void TrackRenderer::RenderSegment(Track& track, int startPointIndex, int endPointIndex, int step)
{
    int i;
    for (i = startPointIndex; i < endPointIndex - step; i += step)
    {
        glBegin(GL_QUADS);

        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(track.InsidePoints[i]);

        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(track.InsidePoints[i + step]);

        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(track.OutsidePoints[i + step]);

        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(track.OutsidePoints[i]);

        glEnd();
    }

    if (i < endPointIndex)
    {
        glBegin(GL_QUADS);

        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(track.InsidePoints[i]);

        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(track.InsidePoints[endPointIndex]);

        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(track.OutsidePoints[endPointIndex]);

        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(track.OutsidePoints[i]);

        glEnd();
    }
}

void TrackRenderer::RenderEdges(Track& track)
{
    glColor3f(1.0f, 1.0f, 1.0f);
    _edgeTexture.Bind();

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

TrackRenderer* TrackRendererResolvingFactory::Make(Resolver&)
{
    return new TrackRenderer();
}
