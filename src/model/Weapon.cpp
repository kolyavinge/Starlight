#include <model/Weapon.h>

Weapon::Weapon() :
    Bullets(_bullets),
    _bulletsIter(_bullets)
{
    _remainingBullets = 0;
    _currentDelay = 0;
    _bullets.PrepareEnoughCapacity(_maxBulletsInQueue);
    for (int i = 0; i < _maxBulletsInQueue; i++)
    {
        _bullets.Add(Bullet());
    }
    IsFireActive = false;
}

void Weapon::Init()
{
    _remainingBullets = 0;
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
    if (_remainingBullets == 0) return;

    Bullet* bullet = FindInactiveBullet();
    if (bullet == nullptr) return;

    bullet->Init();
    InitNewBullet(shipCentralLine, bullet->Position, bullet->Direction);
    if (bullet->Direction.IsZero()) throw WeaponException();
    bullet->MovingDistance = bullet->Direction.GetLength();
    bullet->IsActive = true;
    bullet->DamageValue = GetDamageValue();
    _remainingBullets--;
    IsFireActive = true;
    _currentDelay = GetDelayValue();
}

int Weapon::GetRemainingBullets()
{
    return _remainingBullets;
}

void Weapon::AddBullets(int count)
{
    _remainingBullets += count;
    if (_remainingBullets > GetMaxBulletsCount())
    {
        _remainingBullets = GetMaxBulletsCount();
    }
}

bool Weapon::IsBulletsFull()
{
    return GetRemainingBullets() == GetMaxBulletsCount();
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
