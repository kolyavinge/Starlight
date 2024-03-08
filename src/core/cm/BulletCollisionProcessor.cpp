#include <model/Bullet.h>
#include <core/cm/BulletCollisionResult.h>
#include <core/cm/BulletCollisionProcessor.h>

bool BulletCollisionProcessor::ProcessBulletsCollisions(Ship& targetShip, IArray<Ship*>& allShips)
{
    if (!_bulletCollisionDetector.DetectCollisions(targetShip, allShips)) return false;
    BulletCollisionResult& collisionResult = _bulletCollisionDetector.Result;
    for (int i = 0; i < collisionResult.Bullets.GetCount(); i++)
    {
        Bullet* bullet = collisionResult.Bullets[i];
        bullet->IsActive = false;
        targetShip.Damage(bullet->DamageValue);
    }

    return true;
}
