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
#include <core/BorderUpdater.h>
#include <core/PositionUpdater.h>
#include <core/WeaponLogic.h>
#include <core/ShipStateLogic.h>
#include <core/PowerUpGenerator.h>
#include <core/NitroLogic.h>
#include <core/Laps.h>
#include <core/RaceDistanceCalculator.h>
#include <core/RacePositionUpdater.h>
#include <core/cm/TrackCollisionProcessor.h>
#include <core/cm/ShipCollisionProcessor.h>
#include <core/cm/BulletCollisionProcessor.h>
#include <core/cm/PowerUpCollisionProcessor.h>
#include <ai/EnemyAI.h>

class RaceUpdater : public Object
{
    TurnAngleCalculator& _turnAngleCalculator;
    VelocityCalculator& _velocityCalculator;
    MoveLogic& _moveLogic;
    BorderUpdater& _borderUpdater;
    PositionUpdater& _positionUpdater;
    WeaponLogic& _weaponLogic;
    ShipStateLogic& _shipStateLogic;
    PowerUpGenerator& _powerUpGenerator;
    NitroLogic& _nitroLogic;
    Laps& _laps;
    RaceDistanceCalculator& _raceDistanceCalculator;
    RacePositionUpdater& _racePositionUpdater;
    TrackCollisionProcessor& _trackCollisionProcessor;
    ShipCollisionProcessor& _shipCollisionProcessor;
    BulletCollisionProcessor& _bulletCollisionProcessor;
    PowerUpCollisionProcessor& _powerUpCollisionProcessor;
    EnemyAI& _enemyAI;

public:
    RaceUpdater(
        TurnAngleCalculator& turnAngleCalculator,
        VelocityCalculator& velocityCalculator,
        MoveLogic& moveLogic,
        BorderUpdater& borderUpdater,
        PositionUpdater& positionUpdater,
        WeaponLogic& weaponLogic,
        ShipStateLogic& shipStateLogic,
        PowerUpGenerator& powerUpGenerator,
        NitroLogic& nitroLogic,
        Laps& laps,
        RaceDistanceCalculator& raceDistanceCalculator,
        RacePositionUpdater& racePositionUpdater,
        TrackCollisionProcessor& trackCollisionProcessor,
        ShipCollisionProcessor& shipCollisionProcessor,
        BulletCollisionProcessor& bulletCollisionProcessor,
        PowerUpCollisionProcessor& powerUpCollisionProcessor,
        EnemyAI& enemyAI);

    void Update(
        RaceState& state,
        Ship& player,
        IArray<Ship>& enemies,
        IArray<Ship*>& allShips,
        IArray<PowerUp>& powerUps,
        Track& track);

private:
    void Update(Ship& ship, IArray<Ship*>& allShips, IArray<PowerUp>& powerUps, Track& track);
};

class RaceUpdaterResolvingFactory : public ResolvingFactory<RaceUpdater>
{
public:
    RaceUpdater* Make(Resolver& resolver) override;
};
