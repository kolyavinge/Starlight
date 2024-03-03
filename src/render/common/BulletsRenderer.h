#pragma once

#include <lib/Object.h>
#include <lib/IArray.h>
#include <model/Bullet.h>
#include <model/Ship.h>

class BulletsRenderer : public Object
{
public:
    void Render(Ship& player, IArray<Ship>& enemies);

private:
    void RenderWeapon(Ship& ship);
    void RenderBullet(Bullet& bullet);
};
