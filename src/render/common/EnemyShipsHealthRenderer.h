#pragma once

#include <lib/Object.h>
#include <lib/Collection.h>
#include <lib/di/ResolvingFactory.h>
#include <model/Ship.h>

class EnemyShipsHealthRenderer : public Object
{
public:
    void Render(Ship& player, Collection<Ship>& enemies);

private:
    void Render(Ship& ship);
    bool IsEnemyAheadPlayer(Ship& player, Ship& enemy);
};

class EnemyShipsHealthRendererResolvingFactory : public ResolvingFactory<EnemyShipsHealthRenderer>
{
public:
    EnemyShipsHealthRenderer* Make(Resolver& resolver) override;
};
