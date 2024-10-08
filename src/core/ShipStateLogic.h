#pragma once

#include <lib/Object.h>
#include <lib/di/ResolvingFactory.h>
#include <model/Ship.h>
#include <model/Track.h>
#include <core/cm/ShipCollisionDetector.h>

class ShipStateLogic : public Object
{
    ShipCollisionDetector& _shipCollisionDetector;

public:
    ShipStateLogic(ShipCollisionDetector& shipCollisionDetector);

    void ProcessState(Ship& ship, Collection<Ship*>& allShips, Track& track);

private:
    void SetShipAtMiddle(Ship& ship, Track& track);
};

class ShipStateLogicResolvingFactory : public ResolvingFactory<ShipStateLogic>
{
public:
    ShipStateLogic* Make(Resolver& resolver) override;
};
