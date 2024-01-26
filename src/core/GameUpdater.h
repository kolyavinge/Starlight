#pragma once

#include <model/Ship.h>
#include <model/Track.h>
#include <core/TurnAngleCalculator.h>
#include <core/VelocityCalculator.h>
#include <core/MoveLogic.h>
#include <core/CollisionProcessor.h>
#include <core/PositionCorrector.h>
#include <core/BorderUpdater.h>
#include <core/PositionUpdater.h>
#include <core/LapCounter.h>
#include <core/Camera.h>

class IGameUpdater
{
public:
    virtual void Update() = 0;
};

class GameUpdater : public IGameUpdater
{
    TurnAngleCalculator _turnAngleCalculator;
    VelocityCalculator _velocityCalculator;
    MoveLogic _moveLogic;
    CollisionProcessor _collisionProcessor;
    PositionCorrector _positionCorrector;
    BorderUpdater _borderUpdater;
    PositionUpdater _positionUpdater;
    LapCounter _lapCounter;
    Ship& _player;
    Track& _track;
    Camera& _camera;

public:
    GameUpdater(
        Ship& player,
        Track& track,
        Camera& camera);

    void Update() override;

private:
    void SaveCurrentShipsPositions();
};

class EmptyGameUpdater : public IGameUpdater
{
public:
    void Update() override { }
};
