#include <gl/opengl.h>
#include <render/common/TrackRenderer.h>
#include <anx/GraphicResources.h>

void TrackRenderer::Init()
{
    _groundTexture.Load(GraphicResources::GetTrackGround1TextureFilePath());
    _groundFinishTexture.Load(GraphicResources::GetTrackGroundFinishTextureFilePath());
}

void TrackRenderer::Render(Track& track)
{
    RenderTrack(track);
    RenderEdges(track);
}

void TrackRenderer::RenderTrack(Track& track)
{
    glEnable(GL_BLEND);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);

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

    glDisable(GL_TEXTURE_2D);
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_BLEND);
}

void TrackRenderer::RenderEdges(Track& track)
{
    glColor3f(0.8f, 0.8f, 0.8f);

    glBegin(GL_POINTS);

    for (int i = 0; i < track.PointsCount; i += 25)
    {
        glVertex3f(track.InsidePoints[i]);
        glVertex3f(track.OutsidePoints[i]);
    }

    glEnd();
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

TrackRenderer* TrackRendererResolvingFactory::Make(Resolver&)
{
    return new TrackRenderer();
}
