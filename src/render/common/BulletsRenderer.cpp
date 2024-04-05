#include <gl/opengl.h>
#include <calc/Vector3.h>
#include <core/Constants.h>
#include <render/common/BulletsRenderer.h>

void BulletsRenderer::Render(Ship& player, IArray<Ship>& enemies)
{
    glEnable(GL_DEPTH_TEST);
    RenderWeapon(player);
    for (int i = 0; i < enemies.GetCount(); i++)
    {
        RenderWeapon(enemies[i]);
    }
    glDisable(GL_DEPTH_TEST);
}

void BulletsRenderer::RenderWeapon(Ship& ship)
{
    for (int i = 0; i < ship.Weapon.Bullets.GetCount(); i++)
    {
        Bullet& bullet = ship.Weapon.Bullets[i];
        if (bullet.IsActive)
        {
            RenderBullet(bullet);
        }
    }
}

void BulletsRenderer::RenderBullet(Bullet& bullet)
{
    Vector3 from(bullet.PrevPosition);
    from.Sub(bullet.Position);
    from.SetLength(4.0f);
    from.Add(bullet.Position);

    glLineWidth(2.0f);
    glColor3f(0.8f, 0.0f, 0.0f);
    glBegin(GL_LINES);

    glVertex3f(from);
    glVertex3f(bullet.Position);

    glEnd();
    glLineWidth(Constants::RenderLineWidth);
}

BulletsRenderer* BulletsRendererResolvingFactory::Make(Resolver&)
{
    return new BulletsRenderer();
}
