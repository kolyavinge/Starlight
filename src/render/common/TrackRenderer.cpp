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
    glColor4f(0.5f, 0.5f, 0.5f, 0.2f);

    for (int i = 0; i < track.PointsCount - 1; i++)
    {
        glBegin(GL_QUADS);
        glVertex3f(track.InsidePoints[i]);
        glVertex3f(track.InsidePoints[i + 1]);
        glVertex3f(track.OutsidePoints[i + 1]);
        glVertex3f(track.OutsidePoints[i]);
        glEnd();
    }

    glBegin(GL_QUADS);
    glVertex3f(track.InsidePoints[track.PointsCount - 1]);
    glVertex3f(track.InsidePoints[0]);
    glVertex3f(track.OutsidePoints[0]);
    glVertex3f(track.OutsidePoints[track.PointsCount - 1]);
    glEnd();

    glDisable(GL_BLEND);
}

void TrackRenderer::RenderEdges(Track& track)
{
    glColor3f(0.8f, 0.8f, 0.8f);

    glBegin(GL_POINTS);

    for (int i = 0; i < track.PointsCount; i += 40)
    {
        glVertex3f(track.InsidePoints[i]);
        glVertex3f(track.OutsidePoints[i]);
    }

    glEnd();
}
