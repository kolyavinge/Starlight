#include <glew/glew.h>
#include <gl/opengl.h>
#include <lib/Numeric.h>
#include <calc/Vector3.h>
#include <render/common/EnemyShipsHealthRenderer.h>

void EnemyShipsHealthRenderer::Render(Ship& player, Collection<Ship>& enemies)
{
    for (int i = 0; i < enemies.GetCount(); i++)
    {
        if (IsEnemyAheadPlayer(player, enemies[i]))
        {
            Render(enemies[i]);
        }
    }
}

void EnemyShipsHealthRenderer::Render(Ship& ship)
{
    if (Numeric::FloatEquals(ship.Health, 0.0f)) return;
    if (ship.State != ShipState::Active) return;

    const float barWidth = 0.8f * ship.Health;
    const float barHeight = 0.06f;

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

    if (ship.IsDamaged)
    {
        glColor3f(0.6f, 0.0f, 0.1f);
    }
    else
    {
        glColor3f(0.0f, 0.6f, 0.1f);
    }

    glEnable(GL_MULTISAMPLE);
    glEnable(GL_BLEND);

    glBegin(GL_QUADS);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(position);
    position.Add(down);
    glVertex3f(position);
    glVertex3f(down);
    glEnd();

    glDisable(GL_BLEND);
    glDisable(GL_MULTISAMPLE);

    glPopMatrix();
}

bool EnemyShipsHealthRenderer::IsEnemyAheadPlayer(Ship& player, Ship& enemy)
{
    Vector3 distance(enemy.CentralLine.Front);
    distance.Sub(player.CentralLine.Front);
    float distanceLength = distance.GetLength();
    if (distanceLength > 100.0f)
    {
        return false;
    }
    distance.Div(distanceLength); // Normalize

    Vector3 playerDirection(player.CentralLine.Front);
    playerDirection.Sub(player.CentralLine.Rear);
    playerDirection.Normalize();

    float dot = distance.DotProduct(playerDirection);

    return Numeric::Between(dot, -0.2f, 1.0f);
}

EnemyShipsHealthRenderer* EnemyShipsHealthRendererResolvingFactory::Make(Resolver&)
{
    return new EnemyShipsHealthRenderer();
}
