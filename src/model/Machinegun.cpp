#include <lib/Math.h>
#include <calc/Geometry.h>
#include <model/Machinegun.h>

Machinegun::Machinegun() :
    Weapon(MaxBulletsCount)
{
    _activeBarrel = Barrel::Left;
}

int Machinegun::GetDamageValue()
{
    return 1;
}

float Machinegun::GetMaxBulletDistance()
{
    return 200.0f;
}

void Machinegun::InnerInit()
{
    _activeBarrel = Barrel::Left;
}

int Machinegun::GetDelayValue()
{
    return 5;
}

void Machinegun::InitNewBullet(ShipCentralLine& shipCentralLine, Vector3& bulletPosition, Vector3& bulletDirection)
{
    bulletDirection.Set(shipCentralLine.Front);
    bulletDirection.Sub(shipCentralLine.Rear);
    bulletDirection.SetLength(5.0f);

    bulletPosition.Set(bulletDirection);
    bulletPosition.SetLength(0.12f);
    float radians = _activeBarrel == Barrel::Left ? Math::PiHalf : -Math::PiHalf;
    bulletPosition = Geometry::RotatePoint3d(bulletPosition, shipCentralLine.NormalFront, radians);
    bulletPosition.Add(shipCentralLine.Front);

    SwitchBarrel();
}

void Machinegun::SwitchBarrel()
{
    _activeBarrel = _activeBarrel == Barrel::Left ? Barrel::Right : Barrel::Left;
}
