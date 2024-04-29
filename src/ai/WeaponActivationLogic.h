#pragma once

#include <lib/Object.h>
#include <lib/Collection.h>
#include <lib/di/ResolvingFactory.h>
#include <model/Ship.h>
#include <core/ShipController.h>
#include <core/cm/ShipCollisionDetector.h>

class WeaponActivationLogic : public Object
{
    ShipController& _shipController;
    ShipCollisionDetector& _shipCollisionDetector;

public:
    WeaponActivationLogic(
        ShipController& shipController,
        ShipCollisionDetector& shipCollisionDetector);

    void Apply(Ship& ship, Collection<Ship*>& allShips);

private:
    void TryActivateFire(Ship& ship, Collection<Ship*>& allShips);
    float GetLengthBetweenShips(Ship& ship, Ship& otherShip);
};

class WeaponActivationLogicResolvingFactory : public ResolvingFactory<WeaponActivationLogic>
{
public:
    WeaponActivationLogic* Make(Resolver& resolver) override;
};
