#pragma once

#include <lib/Object.h>
#include <lib/Collection.h>
#include <lib/di/ResolvingFactory.h>
#include <model/Bullet.h>
#include <model/Ship.h>

class BulletsRenderer : public Object
{
public:
    void Render(Ship& player, Collection<Ship>& enemies);

private:
    void RenderWeapon(Ship& ship);
    void RenderBullet(Bullet& bullet);
};

class BulletsRendererResolvingFactory : public ResolvingFactory<BulletsRenderer>
{
public:
    BulletsRenderer* Make(Resolver& resolver) override;
};
