#include <model/Bullet.h>
#include <core/WeaponLogic.h>

void WeaponLogic::UpdateWeapon(Ship& ship)
{
    ship.Weapon.Update();

    if (!ship.IsFireActive) return;

    ship.Weapon.Fire(ship.CentralLine);
}

void WeaponLogic::UpdateBullets(Weapon& weapon)
{
    for (int i = 0; i < weapon.Bullets.GetCount(); i++)
    {
        Bullet& bullet = weapon.Bullets[i];

        if (!bullet.IsActive) continue;

        bullet.TotalDistance += bullet.MovingDistance;
        if (bullet.TotalDistance <= weapon.GetMaxBulletDistance())
        {
            bullet.PrevPosition = bullet.Position;
            bullet.Position.Add(bullet.Direction);
        }
        else
        {
            bullet.IsActive = false;
        }
    }
}
