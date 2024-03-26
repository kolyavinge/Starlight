#include <model/Track.h>
#include <core/RaceUpdater.h>

RaceUpdater::RaceUpdater(
    TurnAngleCalculator& turnAngleCalculator,
    VelocityCalculator& velocityCalculator,
    MoveLogic& moveLogic,
    PositionCorrector& positionCorrector,
    BorderUpdater& borderUpdater,
    PositionUpdater& positionUpdater,
    WeaponLogic& weaponLogic,
    ShipStateLogic& shipStateLogic,
    PowerUpGenerator& powerUpGenerator,
    NitroLogic& nitroLogic,
    Laps& laps,
    TrackCollisionProcessor& trackCollisionProcessor,
    ShipCollisionProcessor& shipCollisionProcessor,
    BulletCollisionProcessor& bulletCollisionProcessor,
    PowerUpCollisionProcessor& powerUpCollisionProcessor,
    EnemyAI& enemyAI) :
    _turnAngleCalculator(turnAngleCalculator),
    _velocityCalculator(velocityCalculator),
    _moveLogic(moveLogic),
    _positionCorrector(positionCorrector),
    _borderUpdater(borderUpdater),
    _positionUpdater(positionUpdater),
    _weaponLogic(weaponLogic),
    _shipStateLogic(shipStateLogic),
    _powerUpGenerator(powerUpGenerator),
    _nitroLogic(nitroLogic),
    _laps(laps),
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
    IArray<Ship>& enemies,
    IArray<Ship*>& allShips,
    IArray<PowerUp>& powerUps,
    Track& track)
{
    Update(player, allShips, powerUps, track);
    for (int i = 0; i < enemies.GetCount(); i++)
    {
        Update(enemies[i], allShips, powerUps, track);
    }
    _enemyAI.ApplyFor(enemies, allShips, track);
    _laps.Update(state, player, track);
    if (_laps.IsLapCompleted && state != RaceState::Finish)
    {
        _powerUpGenerator.UpdatePositions(track, powerUps);
    }
}

void RaceUpdater::Update(Ship& ship, IArray<Ship*>& allShips, IArray<PowerUp>& powerUps, Track& track)
{
    SaveCurrentShipsPositions(ship);
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
    _powerUpCollisionProcessor.ProcessPowerUpsCollisions(ship, powerUps);
    _nitroLogic.ProcessNitro(ship);
    _positionCorrector.CorrectAfterFloatOperations(ship);
}

void RaceUpdater::SaveCurrentShipsPositions(Ship& ship)
{
    ship.PrevCentralLine = ship.CentralLine;
}

RaceUpdater* RaceUpdaterResolvingFactory::Make(Resolver& resolver)
{
    return new RaceUpdater(
        resolver.Resolve<TurnAngleCalculator>(),
        resolver.Resolve<VelocityCalculator>(),
        resolver.Resolve<MoveLogic>(),
        resolver.Resolve<PositionCorrector>(),
        resolver.Resolve<BorderUpdater>(),
        resolver.Resolve<PositionUpdater>(),
        resolver.Resolve<WeaponLogic>(),
        resolver.Resolve<ShipStateLogic>(),
        resolver.Resolve<PowerUpGenerator>(),
        resolver.Resolve<NitroLogic>(),
        resolver.Resolve<Laps>(),
        resolver.Resolve<TrackCollisionProcessor>(),
        resolver.Resolve<ShipCollisionProcessor>(),
        resolver.Resolve<BulletCollisionProcessor>(),
        resolver.Resolve<PowerUpCollisionProcessor>(),
        resolver.Resolve<EnemyAI>());
}
