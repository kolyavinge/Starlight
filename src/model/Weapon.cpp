#include <model/Weapon.h>

Weapon::Weapon(int maxBulletsCount) :
    Bullets(_bullets),
    _bulletsIter(_bullets)
{
    _currentDelay = 0;
    _bullets.PrepareEnoughCapacity(maxBulletsCount);
    for (int i = 0; i < maxBulletsCount; i++)
    {
        _bullets.Add(Bullet());
    }
    IsFireActive = false;
}

void Weapon::Init()
{
    _currentDelay = 0;
    for (int i = 0; i < _bullets.GetCount(); i++)
    {
        _bullets[i].Init();
    }
    _bulletsIter.Reset();
    IsFireActive = false;
    InnerInit();
}

void Weapon::Update()
{
    IsFireActive = false;
    if (_currentDelay > 0) _currentDelay--;
}

void Weapon::Fire(ShipCentralLine& shipCentralLine)
{
    if (_currentDelay > 0) return;

    Bullet* bullet = FindInactiveBullet();
    if (bullet == nullptr) return;

    bullet->Init();
    InitNewBullet(shipCentralLine, bullet->Position, bullet->Direction);
    if (bullet->Direction.IsZero()) throw WeaponException();
    bullet->MovingDistance = bullet->Direction.GetLength();
    bullet->IsActive = true;
    bullet->DamageValue = GetDamageValue();

    IsFireActive = true;
    _currentDelay = GetDelayValue();
}

void Weapon::InnerInit()
{
}

Bullet* Weapon::FindInactiveBullet()
{
    for (int i = 0; i < _bullets.GetCount(); i++)
    {
        if (!_bulletsIter.GetCurrentItem().IsActive)
        {
            return &_bulletsIter.GetCurrentItem();
        }
        else
        {
            _bulletsIter.Next();
        }
    }

    return nullptr;
}
