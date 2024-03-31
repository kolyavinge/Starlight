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

    void CalculateMovingDirection(Ship& ship, IArray<Ship*>& allShips, Track& track);

private:
    void TryCalculateMovingDirection(Ship& ship, IArray<Ship*>& allShips, Track& track, float directionLength);
    void GenerateAvailableDirections(Ship& ship, float directionLength);
    void EnableDirections(Ship& ship, IArray<Ship*>& allShips, Track& track, float directionLength);
    bool IsDirectionEnabled(Ship& ship, IArray<Ship*>& allShips, Track& track, Vector3 direction, float directionLength);
    float GetLengthBetweenShips(Ship& ship, Ship& otherShip);
    void CalculateResultDirection(ShipMovingDirections& movingDirections);
};

class ObstacleAvoidanceLogicResolvingFactory : public ResolvingFactory<ObstacleAvoidanceLogic>
{
public:
    ObstacleAvoidanceLogic* Make(Resolver& resolver) override;
};
