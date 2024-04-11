#include <gl/opengl.h>
#include <render/debug/DebugRenderLogic.h>

DebugRenderLogic::DebugRenderLogic(Race& race) :
    _race(race)
{
}

void DebugRenderLogic::Render(Screen&)
{
    RenderGrid();
    _backgroundRenderer.Render();
    _trackRenderer.Render(*_race.Track);
    _shipRenderer.Render(_race.Player, *_race.Track);
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
    float length = 1000.0f;

    glColor3f(0.1f, 0.1f, 0.1f);
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
