#pragma once

#include <lib/Object.h>
#include <lib/Collection.h>
#include <lib/di/ResolvingFactory.h>
#include <model/Ship.h>

class EnemyShipsHealthRenderer : public Object
{
public:
    void Render(Collection<Ship>& enemies);

private:
    void Render(Ship& ship);
};

class EnemyShipsHealthRendererResolvingFactory : public ResolvingFactory<EnemyShipsHealthRenderer>
{
public:
    EnemyShipsHealthRenderer* Make(Resolver& resolver) override;
};
