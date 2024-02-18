#include <model/Track.h>
#include <core/Constants.h>
#include <core/RaceUpdater.h>

RaceUpdater::RaceUpdater(EnemyAI& enemyAI) :
    _enemyAI(enemyAI)
{
}

void RaceUpdater::Update(
    RaceState& state,
    Ship& player,
    List<Ship>& enemies,
    Track& track,
    Laps& laps)
{
    Update(player, track);
    for (int i = 0; i < enemies.Count(); i++)
    {
        Update(enemies[i], track);
    }
    _enemyAI.ApplyFor(enemies, track);
    laps.Update(state, player, track);
}

void RaceUpdater::Update(Ship& ship, Track& track)
{
    SaveCurrentShipsPositions(ship);
    _positionUpdater.UpdateIfShipMoving(ship, track);
    _turnAngleCalculator.CalculateTurnAngle(ship);
    _velocityCalculator.CalculateVelocity(Constants::TimeStep, ship);
    _moveLogic.MoveShip(Constants::TimeStep, ship);
    _borderUpdater.Update(ship);
    _collisionProcessor.ProcessCollisions(ship, track);
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
