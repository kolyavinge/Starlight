#include <gl/opengl.h>
#include <calc/Vector3.h>
#include <calc/Sphere.h>
#include <render/DebugTrackRenderer.h>

void DebugTrackRenderer::Render(Track& track)
{
    RenderBackground();
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
        Vector3& from = track.InsidePoints[i];
        Vector3& to = track.InsidePoints[i + 1];
        glVertex3f(from);
        glVertex3f(to);
    }

    Vector3& from = track.InsidePoints[track.PointsCount - 1];
    Vector3& to = track.InsidePoints[0];
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
        Vector3& from = track.OutsidePoints[i];
        Vector3& to = track.OutsidePoints[i + 1];
        glVertex3f(from);
        glVertex3f(to);
    }

    Vector3& from = track.OutsidePoints[track.PointsCount - 1];
    Vector3& to = track.OutsidePoints[0];
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
        Vector3& from = track.InsidePoints[i];
        Vector3& to = track.OutsidePoints[i];
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
        Array<Vector3, TrackMaxMiddlePoints>& middlePoints = track.MiddlePoints[i];
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
        Vector3& normal = track.Normals[i];
        Vector3& out = track.OutsidePoints[i];
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

    Vector3& from = track.InsidePoints[track.StartFinishLineIndex];
    Vector3& to = track.OutsidePoints[track.StartFinishLineIndex];
    glVertex3f(from);
    glVertex3f(to);

    glEnd();
}

void DebugTrackRenderer::RenderBackground()
{
    Sphere sphere(1000.0f, 4, 20);
    glColor3f(0.2f, 0.2f, 0.2f);

    for (int level = -sphere.GetLevelsCount(); level < sphere.GetLevelsCount(); level++)
    {
        for (int point = 0; point < sphere.GetLevelPointsCount() - 1; point++)
        {
            glBegin(GL_LINE_LOOP);
            glVertex3f(sphere.GetPoint(level, point));
            glVertex3f(sphere.GetPoint(level + 1, point));
            glVertex3f(sphere.GetPoint(level + 1, point + 1));
            glVertex3f(sphere.GetPoint(level, point + 1));
            glEnd();
        }

        glBegin(GL_LINE_LOOP);
        glVertex3f(sphere.GetPoint(level, sphere.GetLevelPointsCount() - 1));
        glVertex3f(sphere.GetPoint(level + 1, sphere.GetLevelPointsCount() - 1));
        glVertex3f(sphere.GetPoint(level + 1, 0));
        glVertex3f(sphere.GetPoint(level, 0));
        glEnd();
    }
}
