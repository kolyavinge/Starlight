#include <gl/opengl.h>
#include <calc/Sphere.h>
#include <render/release/BackgroundRenderer.h>

void BackgroundRenderer::Render()
{
    Sphere sphere(1000.0f, 8, 45);
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
