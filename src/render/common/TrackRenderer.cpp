#include <gl/opengl.h>
#include <render/common/TrackRenderer.h>

void TrackRenderer::Render(Track& track)
{
    RenderTrack(track);
    RenderEdges(track);
}

void TrackRenderer::RenderTrack(Track& track)
{
    glEnable(GL_BLEND);

    const int step = 25;
    glColor4f(0.5f, 0.5f, 0.5f, 0.2f);
    RenderSegment(track, 0, track.StartFinishLineIndex, step);

    glColor4f(0.8f, 0.2f, 0.5f, 0.2f);
    RenderSegment(track, track.StartFinishLineIndex, track.StartFinishLineIndex + step, step);

    glColor4f(0.5f, 0.5f, 0.5f, 0.2f);
    RenderSegment(track, track.StartFinishLineIndex + step, track.PointsCount, step);

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
        glVertex3f(track.InsidePoints[i]);
        glVertex3f(track.InsidePoints[i + step]);
        glVertex3f(track.OutsidePoints[i + step]);
        glVertex3f(track.OutsidePoints[i]);
        glEnd();
    }

    if (i < endPointIndex)
    {
        glBegin(GL_QUADS);
        glVertex3f(track.InsidePoints[i]);
        glVertex3f(track.InsidePoints[endPointIndex]);
        glVertex3f(track.OutsidePoints[endPointIndex]);
        glVertex3f(track.OutsidePoints[i]);
        glEnd();
    }
}

TrackRenderer* TrackRendererResolvingFactory::Make(Resolver&)
{
    return new TrackRenderer();
}
