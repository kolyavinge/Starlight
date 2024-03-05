#include <gl/opengl.h>
#include <calc/Vector3.h>
#include <render/common/EnemyShipsHealthRenderer.h>

void EnemyShipsHealthRenderer::Render(IArray<Ship>& enemies)
{
    for (int i = 0; i < enemies.GetCount(); i++)
    {
        Render(enemies[i]);
    }
}

void EnemyShipsHealthRenderer::Render(Ship& ship)
{
    const float barWidth = 0.7f * ship.Health;
    const float barHeight = 0.04f;

    Vector3 down(ship.CentralLine.NormalRear);
    down.SetLength(barHeight);
    down.Mul(-1.0f);

    glPushMatrix();

    Vector3 position(ship.Border.DownLeft);
    position.Sub(ship.Border.DownRight);
    position.SetLength(barWidth / 2.0f);
    glTranslatef(ship.CentralLine.Rear);
    glTranslatef(position);
    position.Mul(-2.0f);

    glColor3f(0.0f, 0.6f, 0.1f);
    glEnable(GL_DEPTH_TEST);
    glBegin(GL_QUADS);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(position);
    position.Add(down);
    glVertex3f(position);
    glVertex3f(down);
    glEnd();
    glDisable(GL_DEPTH_TEST);

    glPopMatrix();
}
