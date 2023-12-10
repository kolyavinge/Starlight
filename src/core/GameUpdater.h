#pragma once

#include "lib/Object.h"
#include "model/Ship.h"
#include "model/Track.h"
#include "core/TurnAngleCalculator.h"
#include "core/VelocityCalculator.h"
#include "core/MoveLogic.h"
#include "core/CollisionProcessor.h"
#include "core/PositionCorrector.h"
#include "core/BorderUpdater.h"
#include "core/ZCalculator.h"
#include "core/GameCamera.h"

class GameUpdater : public Object
{
    TurnAngleCalculator _turnAngleCalculator;
    VelocityCalculator _velocityCalculator;
    MoveLogic _moveLogic;
    CollisionProcessor _collisionProcessor;
    PositionCorrector _positionCorrector;
    BorderUpdater _borderUpdater;
    ZCalculator _zCalculator;
    Ship& _player;
    Track& _track;
    GameCamera& _camera;

public:
    GameUpdater(
        Ship& player,
        Track& track,
        GameCamera& camera);

    void Update();

private:
    void SaveCurrentShipsPositions();
};
