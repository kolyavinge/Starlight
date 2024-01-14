#include <gl/opengl.h>
#include <render/debug/DebugBackgroundRenderer.h>

DebugBackgroundRenderer::DebugBackgroundRenderer()
{
}

void DebugBackgroundRenderer::Render()
{
    glColor3f(0.2f, 0.2f, 0.2f);

    for (int level = -_sphere.GetLevelsCount(); level < _sphere.GetLevelsCount(); level++)
    {
        for (int point = 0; point < _sphere.GetLevelPointsCount() - 1; point++)
        {
            glBegin(GL_LINE_LOOP);
            glVertex3f(_sphere.GetPoint(level, point));
            glVertex3f(_sphere.GetPoint(level + 1, point));
            glVertex3f(_sphere.GetPoint(level + 1, point + 1));
            glVertex3f(_sphere.GetPoint(level, point + 1));
            glEnd();
        }

        glBegin(GL_LINE_LOOP);
        glVertex3f(_sphere.GetPoint(level, _sphere.GetLevelPointsCount() - 1));
        glVertex3f(_sphere.GetPoint(level + 1, _sphere.GetLevelPointsCount() - 1));
        glVertex3f(_sphere.GetPoint(level + 1, 0));
        glVertex3f(_sphere.GetPoint(level, 0));
        glEnd();
    }
}
