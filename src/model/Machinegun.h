#pragma once

#include <calc/Vector3.h>
#include <model/ShipCentralLine.h>
#include <model/Weapon.h>

class Machinegun : public Weapon
{
    enum class Barrel { Left, Right };

    Barrel _activeBarrel;

public:
    inline static const int MaxBulletsCount = 100;

    Machinegun();

    float GetDamageValue() override;

protected:
    void InnerInit() override;
    int GetDelayValue() override;
    float GetMaxBulletDistance() override;
    void InitNewBullet(ShipCentralLine& shipCentralLine, Vector3& bulletPosition, Vector3& bulletDirection) override;

private:
    void SwitchBarrel();
};
