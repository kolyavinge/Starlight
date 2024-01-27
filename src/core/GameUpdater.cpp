#include <model/Track.h>
#include <core/Constants.h>
#include <core/GameUpdater.h>

GameUpdater::GameUpdater(
    Ship& player,
    TrackManager& trackManager,
    Camera& camera) :
    _player(player),
    _trackManager(trackManager),
    _camera(camera)
{
}

void GameUpdater::Update()
{
    SaveCurrentShipsPositions();
    Track& track = _trackManager.GetCurrentTrack();
    _positionUpdater.UpdateIfShipMoving(_player, track);
    float timeStep = Constants::TimeStep;
    _turnAngleCalculator.CalculateTurnAngle(_player);
    _velocityCalculator.CalculateVelocity(timeStep, _player);
    _moveLogic.MoveShip(timeStep, _player);
    _borderUpdater.Update(_player);
    _collisionProcessor.ProcessCollisions(_player, track);
    if (_collisionProcessor.HasCollisions())
    {
        _borderUpdater.Update(_player);
    }
    _positionCorrector.CorrectAfterFloatOperations(_player);
    _lapCounter.CheckLap(_player, track);
    _camera.Update(_player);
}

void GameUpdater::SaveCurrentShipsPositions()
{
    _player.PrevCentralLine = _player.CentralLine;
}
