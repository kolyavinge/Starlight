#include <model/Bullet.h>
#include <core/cm/BulletCollisionProcessor.h>

BulletCollisionProcessor::BulletCollisionProcessor(BulletCollisionDetector& bulletCollisionDetector) :
    _bulletCollisionDetector(bulletCollisionDetector)
{
}

bool BulletCollisionProcessor::ProcessBulletsCollisions(Ship& targetShip, Collection<Ship*>& allShips)
{
    targetShip.IsDamaged = false;
    if (targetShip.State == ShipState::Prepared) return false;
    if (!_bulletCollisionDetector.DetectCollisions(targetShip, allShips)) return false;
    BulletCollisionResult& collisionResult = _bulletCollisionDetector.Result;
    for (int i = 0; i < collisionResult.Bullets.GetCount(); i++)
    {
        Bullet* bullet = collisionResult.Bullets[i];
        bullet->IsActive = false;
        targetShip.Damage(bullet->DamageValue);
        targetShip.IsDamaged = true;
    }

    return true;
}

BulletCollisionProcessor* BulletCollisionProcessorResolvingFactory::Make(Resolver& resolver)
{
    return new BulletCollisionProcessor(resolver.Resolve<BulletCollisionDetector>());
}
