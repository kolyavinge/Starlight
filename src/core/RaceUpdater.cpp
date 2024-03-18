#include <model/Track.h>
#include <core/RaceUpdater.h>

RaceUpdater::RaceUpdater(EnemyAI& enemyAI) :
    _enemyAI(enemyAI)
{
}

void RaceUpdater::Update(
    RaceState& state,
    Ship& player,
    IArray<Ship>& enemies,
    IArray<Ship*>& allShips,
    IArray<PowerUp>& powerUps,
    Track& track,
    Laps& laps)
{
    Update(player, allShips, powerUps, track);
    for (int i = 0; i < enemies.GetCount(); i++)
    {
        Update(enemies[i], allShips, powerUps, track);
    }
    _enemyAI.ApplyFor(enemies, allShips, track);
    laps.Update(state, player, track);
    if (laps.IsLapCompleted)
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
    _positionCorrector.CorrectAfterFloatOperations(ship);
}

void RaceUpdater::SaveCurrentShipsPositions(Ship& ship)
{
    ship.PrevCentralLine = ship.CentralLine;
}
