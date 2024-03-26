#pragma once

#include <lib/Object.h>
#include <lib/di/ResolvingFactory.h>
#include <model/Weapon.h>
#include <model/Ship.h>

class WeaponLogic : public Object
{
public:
    void UpdateWeapon(Ship& ship);
    void UpdateBullets(Weapon& weapon);
};

class WeaponLogicResolvingFactory : public ResolvingFactory<WeaponLogic>
{
public:
    WeaponLogic* Make(Resolver& resolver) override;
};
