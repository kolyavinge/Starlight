#pragma once

#include <lib/Object.h>
#include <lib/IArray.h>
#include <lib/di/ResolvingFactory.h>
#include <calc/Vector3.h>
#include <model/Ship.h>
#include <model/Track.h>
#include <core/cm/TrackCollisionDetector.h>
#include <core/cm/ShipCollisionDetector.h>

class ObstacleAvoidanceLogic : public Object
{
    TrackCollisionDetector& _trackCollisionDetector;
    ShipCollisionDetector& _shipCollisionDetector;

public:
    ObstacleAvoidanceLogic(
        TrackCollisionDetector& trackCollisionDetector,
        ShipCollisionDetector& shipCollisionDetector);

    Vector3 GetMovingDirection(Ship& ship, IArray<Ship*>& allShips, Track& track);

private:
    Vector3 TryGetMovingDirection(Ship& ship, IArray<Ship*>& allShips, Track& track, float directionLength);
    void AddResultIfCorrect(Ship& ship, IArray<Ship*>& allShips, Track& track, Vector3 direction, Vector3& result);
};

class ObstacleAvoidanceLogicResolvingFactory : public ResolvingFactory<ObstacleAvoidanceLogic>
{
public:
    ObstacleAvoidanceLogic* Make(Resolver& resolver) override;
};
