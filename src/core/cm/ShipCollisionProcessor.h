#pragma once

#include <lib/Object.h>
#include <lib/Collection.h>
#include <lib/di/ResolvingFactory.h>
#include <model/Ship.h>
#include <core/cm/ShipCollisionDetector.h>

class ShipCollisionProcessor : public Object
{
    ShipCollisionDetector& _shipCollisionDetector;

public:
    ShipCollisionProcessor(ShipCollisionDetector& shipCollisionDetector);

    bool ProcessShipsCollisions(Ship& ship, Collection<Ship*>& allShips);
};

class ShipCollisionProcessorResolvingFactory : public ResolvingFactory<ShipCollisionProcessor>
{
public:
    ShipCollisionProcessor* Make(Resolver& resolver) override;
};
