#include <core/RaceUpdater.h>

RaceUpdater::RaceUpdater(
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
    EnemyAI& enemyAI) :
    _turnAngleCalculator(turnAngleCalculator),
    _velocityCalculator(velocityCalculator),
    _moveLogic(moveLogic),
    _borderUpdater(borderUpdater),
    _positionUpdater(positionUpdater),
    _weaponLogic(weaponLogic),
    _shipStateLogic(shipStateLogic),
    _powerUpGenerator(powerUpGenerator),
    _nitroLogic(nitroLogic),
    _laps(laps),
    _raceDistanceCalculator(raceDistanceCalculator),
    _racePositionUpdater(racePositionUpdater),
    _trackCollisionProcessor(trackCollisionProcessor),
    _shipCollisionProcessor(shipCollisionProcessor),
    _bulletCollisionProcessor(bulletCollisionProcessor),
    _powerUpCollisionProcessor(powerUpCollisionProcessor),
    _enemyAI(enemyAI)
{
}

void RaceUpdater::Update(
    RaceState& state,
    Ship& player,
    Collection<Ship>& enemies,
    Collection<Ship*>& allShips,
    Collection<Ship*>& allShipsSortedByPositions,
    Collection<PowerUp>& powerUps,
    Track& track)
{
    for (int i = 0; i < allShips.GetCount(); i++)
    {
        Update(*allShips[i], allShips, powerUps, track);
    }
    if (state != RaceState::Finish)
    {
        _racePositionUpdater.Update(allShipsSortedByPositions);
    }
    _enemyAI.ApplyFor(enemies, allShips, track);
    _laps.Update(state, player, track);
    if (_laps.IsLapCompleted && state != RaceState::Finish)
    {
        _powerUpGenerator.UpdatePositions(track, powerUps);
    }
}

void RaceUpdater::Update(Ship& ship, Collection<Ship*>& allShips, Collection<PowerUp>& powerUps, Track& track)
{
    ship.SaveCurrentCentralLine();
    _positionUpdater.UpdateIfShipMoving(ship, track);
    _turnAngleCalculator.CalculateTurnAngle(ship);
    _velocityCalculator.CalculateVelocity(ship);
    _moveLogic.MoveShip(ship);
    _borderUpdater.Update(ship);
    _weaponLogic.UpdateWeapon(ship);
    _weaponLogic.UpdateBullets(ship.Weapon);
    _shipStateLogic.ProcessState(ship, allShips, track);
    bool hasCollisions =
        _trackCollisionProcessor.ProcessTrackCollisions(ship, track) ||
        _shipCollisionProcessor.ProcessShipsCollisions(ship, allShips) ||
        _bulletCollisionProcessor.ProcessBulletsCollisions(ship, allShips);
    if (hasCollisions)
    {
        _borderUpdater.Update(ship);
    }
    _raceDistanceCalculator.CalculateRaceDistance(ship, track);
    _powerUpCollisionProcessor.ProcessPowerUpsCollisions(ship, powerUps);
    _nitroLogic.ProcessNitro(ship);
    _positionUpdater.CorrectAfterFloatOperations(ship);
}

RaceUpdater* RaceUpdaterResolvingFactory::Make(Resolver& resolver)
{
    return new RaceUpdater(
        resolver.Resolve<TurnAngleCalculator>(),
        resolver.Resolve<VelocityCalculator>(),
        resolver.Resolve<MoveLogic>(),
        resolver.Resolve<BorderUpdater>(),
        resolver.Resolve<PositionUpdater>(),
        resolver.Resolve<WeaponLogic>(),
        resolver.Resolve<ShipStateLogic>(),
        resolver.Resolve<PowerUpGenerator>(),
        resolver.Resolve<NitroLogic>(),
        resolver.Resolve<Laps>(),
        resolver.Resolve<RaceDistanceCalculator>(),
        resolver.Resolve<RacePositionUpdater>(),
        resolver.Resolve<TrackCollisionProcessor>(),
        resolver.Resolve<ShipCollisionProcessor>(),
        resolver.Resolve<BulletCollisionProcessor>(),
        resolver.Resolve<PowerUpCollisionProcessor>(),
        resolver.Resolve<EnemyAI>());
}
