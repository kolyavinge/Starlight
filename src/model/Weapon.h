#pragma once

#include <lib/Object.h>
#include <lib/Exceptions.h>
#include <lib/Collection.h>
#include <lib/List.h>
#include <lib/CycledIterator.h>
#include <calc/Vector3.h>
#include <model/ShipCentralLine.h>
#include <model/Bullet.h>

class WeaponException : public Exception { };

class Weapon : public Object
{
    inline static const int _maxBulletsInQueue = 100;

    int _remainingBullets;
    int _currentDelay;
    List<Bullet> _bullets;
    CycledIterator<Bullet> _bulletsIter;

public:
    Collection<Bullet>& Bullets;
    bool IsFireActive;

    Weapon();

    virtual float GetDamageValue() = 0;
    virtual int GetMaxBulletsCount() = 0;
    virtual float GetMaxBulletDistance() = 0;

    void Init();
    void Update();
    void Fire(ShipCentralLine& shipCentralLine);
    int GetRemainingBullets();
    void AddBullets(int count);
    bool IsBulletsFull();

protected:
    virtual void InnerInit();
    virtual int GetDelayValue() = 0;
    virtual void InitNewBullet(ShipCentralLine& shipCentralLine, Vector3& bulletPosition, Vector3& bulletDirection) = 0;

private:
    Bullet* FindInactiveBullet();
};
