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
    Track& track,
    Laps& laps)
{
    Update(player, allShips, track);
    for (int i = 0; i < enemies.GetCount(); i++)
    {
        Update(enemies[i], allShips, track);
    }
    _enemyAI.ApplyFor(enemies, allShips, track);
    laps.Update(state, player, track);
}

void RaceUpdater::Update(Ship& ship, IArray<Ship*>& allShips, Track& track)
{
    SaveCurrentShipsPositions(ship);
    _positionUpdater.UpdateIfShipMoving(ship, track);
    _turnAngleCalculator.CalculateTurnAngle(ship);
    _velocityCalculator.CalculateVelocity(ship);
    _moveLogic.MoveShip(ship);
    _borderUpdater.Update(ship);
    _collisionProcessor.ProcessCollisions(ship, allShips, track);
    if (_collisionProcessor.HasCollisions())
    {
        _borderUpdater.Update(ship);
    }
    _positionCorrector.CorrectAfterFloatOperations(ship);
}

void RaceUpdater::SaveCurrentShipsPositions(Ship& ship)
{
    ship.PrevCentralLine = ship.CentralLine;
}
