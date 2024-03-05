#pragma once

#include <lib/Object.h>
#include <lib/IArray.h>
#include <model/Ship.h>

class EnemyShipsHealthRenderer : public Object
{
public:
    void Render(IArray<Ship>& enemies);

private:
    void Render(Ship& ship);
};
