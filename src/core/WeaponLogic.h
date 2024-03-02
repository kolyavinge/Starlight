#pragma once

#include <lib/Object.h>
#include <model/Weapon.h>
#include <model/Ship.h>

class WeaponLogic : public Object
{
public:
    void UpdateWeapon(Ship& ship);
    void UpdateBullets(Weapon& weapon);
};
