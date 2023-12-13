#include <gl/opengl.h>
#include <render/DebugRenderLogic.h>

void DebugRenderLogic::Render(Game& game)
{
    RenderGrid();
    _trackRenderer.Render(game.CurrentTrack);
    _shipRenderer.Render(game.Player);
    RenderAxis();
}

void DebugRenderLogic::RenderAxis()
{
    glBegin(GL_LINES);

    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(5.0f, 0.0f, 0.0f);

    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 5.0f, 0.0f);

    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 5.0f);

    glEnd();
}

void DebugRenderLogic::RenderGrid()
{
    float length = 100.0f;

    glColor3f(0.05f, 0.05f, 0.05f);
    glBegin(GL_LINES);

    for (float step = -length; step < length; step += 1.0f)
    {
        glVertex3f(step, -length, 0.0f);
        glVertex3f(step, length, 0.0f);
        glVertex3f(-length, step, 0.0f);
        glVertex3f(length, step, 0.0f);
    }

    glEnd();
}
