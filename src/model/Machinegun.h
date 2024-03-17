#pragma once

#include <calc/Vector3.h>
#include <model/ShipCentralLine.h>
#include <model/Weapon.h>

class Machinegun : public Weapon
{
    enum class Barrel { Left, Right };

    Barrel _activeBarrel;

public:
    Machinegun();

    float GetDamageValue() override;
    int GetMaxBulletsCount() override;
    float GetMaxBulletDistance() override;

protected:
    void InnerInit() override;
    int GetDelayValue() override;
    void InitNewBullet(ShipCentralLine& shipCentralLine, Vector3& bulletPosition, Vector3& bulletDirection) override;

private:
    void SwitchBarrel();
};
