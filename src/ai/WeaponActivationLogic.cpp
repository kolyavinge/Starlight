#include <calc/Vector3.h>
#include <ai/WeaponActivationLogic.h>

WeaponActivationLogic::WeaponActivationLogic(
    ShipController& shipController,
    ShipCollisionDetector& shipCollisionDetector) :
    _shipController(shipController),
    _shipCollisionDetector(shipCollisionDetector)
{
}

void WeaponActivationLogic::Apply(Ship& ship, Collection<Ship*>& allShips)
{
    if (ship.AIData.WeaponFireIterations > 0)
    {
        ship.AIData.WeaponFireIterations--;
    }
    else
    {
        TryActivateFire(ship, allShips);
    }
}

void WeaponActivationLogic::TryActivateFire(Ship& ship, Collection<Ship*>& allShips)
{
    _shipController.SetShip(ship);
    _shipController.ReleaseFire();
    for (int i = 0; i < allShips.GetCount(); i++)
    {
        Ship& otherShip = *allShips[i];
        if (Object::ReferenceEquals(ship, otherShip)) continue;
        if (otherShip.State != ShipState::Active) continue;
        if (GetLengthBetweenShips(ship, otherShip) > ship.Weapon.GetMaxBulletDistance()) continue;
        Vector3 to(ship.CentralLine.Front);
        to.Sub(ship.CentralLine.Rear);
        to.SetLength(ship.Weapon.GetMaxBulletDistance());
        to.Add(ship.CentralLine.Front);
        if (_shipCollisionDetector.DetectCollisions(otherShip, ship.CentralLine.Front, to, 1.0f))
        {
            _shipController.ActivateFire();
            ship.AIData.WeaponFireIterations = 10;
        }
    }
}

float WeaponActivationLogic::GetLengthBetweenShips(Ship& ship, Ship& otherShip)
{
    Vector3 length(ship.CentralLine.Front);
    length.Sub(otherShip.CentralLine.Rear);

    return length.GetLength();
}

WeaponActivationLogic* WeaponActivationLogicResolvingFactory::Make(Resolver& resolver)
{
    return new WeaponActivationLogic(
        resolver.Resolve<ShipController>(),
        resolver.Resolve<ShipCollisionDetector>());
}
