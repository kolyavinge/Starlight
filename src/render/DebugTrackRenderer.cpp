#include <gl/opengl.h>
#include <lib/Array.h>
#include <calc/Vector3d.h>
#include <render/DebugTrackRenderer.h>

void DebugTrackRenderer::Render(Track& track)
{
    RenderInsideLines(track);
    RenderOutsideLines(track);
    RenderAcrossLines(track);
    //RenderMiddlePoints(track);
    RenderNormals(track);
    RenderStartFinishLine(track);
}

void DebugTrackRenderer::RenderInsideLines(Track& track)
{
    glColor3f(0.4f, 0.4f, 0.4f);

    glBegin(GL_LINES);

    for (int i = 0; i < track.PointsCount - 1; i++)
    {
        Vector3d& from = track.InsidePoints[i];
        Vector3d& to = track.InsidePoints[i + 1];
        glVertex3f(from);
        glVertex3f(to);
    }

    Vector3d& from = track.InsidePoints[track.PointsCount - 1];
    Vector3d& to = track.InsidePoints[0];
    glVertex3f(from);
    glVertex3f(to);

    glEnd();
}

void DebugTrackRenderer::RenderOutsideLines(Track& track)
{
    glColor3f(0.4f, 0.4f, 0.4f);

    glBegin(GL_LINES);

    for (int i = 0; i < track.PointsCount - 1; i++)
    {
        Vector3d& from = track.OutsidePoints[i];
        Vector3d& to = track.OutsidePoints[i + 1];
        glVertex3f(from);
        glVertex3f(to);
    }

    Vector3d& from = track.OutsidePoints[track.PointsCount - 1];
    Vector3d& to = track.OutsidePoints[0];
    glVertex3f(from);
    glVertex3f(to);

    glEnd();
}

void DebugTrackRenderer::RenderAcrossLines(Track& track)
{
    glColor3f(0.25f, 0.25f, 0.25f);

    glBegin(GL_LINES);

    for (int i = 0; i < track.PointsCount; i++)
    {
        Vector3d& from = track.InsidePoints[i];
        Vector3d& to = track.OutsidePoints[i];
        glVertex3f(from);
        glVertex3f(to);
    }

    glEnd();
}

void DebugTrackRenderer::RenderMiddlePoints(Track& track)
{
    glColor3f(0.6f, 0.6f, 0.6f);

    glBegin(GL_POINTS);

    for (int i = 0; i < track.PointsCount; i++)
    {
        Array<Vector3d, TrackMaxMiddlePoints>& middlePoints = track.MiddlePoints[i];
        for (int j = 0; j < middlePoints.Count; j++)
        {
            glVertex3f(middlePoints[j]);
        }
    }

    glEnd();
}

void DebugTrackRenderer::RenderNormals(Track& track)
{
    glColor3f(0.25f, 0.25f, 0.25f);

    for (int i = 0; i < track.PointsCount; i++)
    {
        Vector3d& normal = track.Normals[i];
        Vector3d& out = track.OutsidePoints[i];
        glPushMatrix();
        glTranslatef(out);
        glBegin(GL_LINES);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(normal);
        glEnd();
        glPopMatrix();
    }
}

void DebugTrackRenderer::RenderStartFinishLine(Track& track)
{
    glColor3f(0.5f, 0.5f, 0.0f);

    glBegin(GL_LINES);

    Vector3d& from = track.InsidePoints[track.StartFinishLineIndex];
    Vector3d& to = track.OutsidePoints[track.StartFinishLineIndex];
    glVertex3f(from);
    glVertex3f(to);

    glEnd();
}
