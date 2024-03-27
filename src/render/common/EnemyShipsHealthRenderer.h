#pragma once

#include <lib/Object.h>
#include <lib/IArray.h>
#include <lib/di/ResolvingFactory.h>
#include <model/Ship.h>

class EnemyShipsHealthRenderer : public Object
{
public:
    void Render(IArray<Ship>& enemies);

private:
    void Render(Ship& ship);
};

class EnemyShipsHealthRendererResolvingFactory : public ResolvingFactory<EnemyShipsHealthRenderer>
{
public:
    EnemyShipsHealthRenderer* Make(Resolver& resolver) override;
};
