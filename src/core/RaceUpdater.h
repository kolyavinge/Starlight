#pragma once

#include <lib/Object.h>
#include <lib/IArray.h>
#include <lib/di/ResolvingFactory.h>
#include <model/Ship.h>
#include <model/Track.h>
#include <model/PowerUp.h>
#include <core/RaceState.h>
#include <core/TurnAngleCalculator.h>
#include <core/VelocityCalculator.h>
#include <core/MoveLogic.h>
#include <core/PositionCorrector.h>
#include <core/BorderUpdater.h>
#include <core/PositionUpdater.h>
#include <core/WeaponLogic.h>
#include <core/ShipStateLogic.h>
#include <core/PowerUpGenerator.h>
#include <core/NitroLogic.h>
#include <core/Laps.h>
#include <core/cm/TrackCollisionProcessor.h>
#include <core/cm/ShipCollisionProcessor.h>
#include <core/cm/BulletCollisionProcessor.h>
#include <core/cm/PowerUpCollisionProcessor.h>
#include <ai/EnemyAI.h>

class RaceUpdater : public Object
{
    TurnAngleCalculator _turnAngleCalculator;
    VelocityCalculator _velocityCalculator;
    MoveLogic _moveLogic;
    TrackCollisionProcessor _trackCollisionProcessor;
    ShipCollisionProcessor _shipCollisionProcessor;
    BulletCollisionProcessor _bulletCollisionProcessor;
    PowerUpCollisionProcessor _powerUpCollisionProcessor;
    PositionCorrector _positionCorrector;
    BorderUpdater _borderUpdater;
    PositionUpdater _positionUpdater;
    WeaponLogic _weaponLogic;
    ShipStateLogic _shipStateLogic;
    PowerUpGenerator _powerUpGenerator;
    NitroLogic _nitroLogic;
    EnemyAI& _enemyAI;

public:
    RaceUpdater(EnemyAI& enemyAI);

    void Update(
        RaceState& state,
        Ship& player,
        IArray<Ship>& enemies,
        IArray<Ship*>& allShips,
        IArray<PowerUp>& powerUps,
        Track& track,
        Laps& laps);

private:
    void Update(Ship& ship, IArray<Ship*>& allShips, IArray<PowerUp>& powerUps, Track& track);
    void SaveCurrentShipsPositions(Ship& ship);
};

class RaceUpdaterResolvingFactory : public ResolvingFactory<RaceUpdater>
{
public:
    RaceUpdater* Make(Resolver& resolver) override;
};
