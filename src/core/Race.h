#pragma once

#include <lib/Object.h>
#include <model/Ship.h>
#include <model/Track.h>
#include <core/ShipController.h>
#include <core/GameUpdater.h>
#include <core/Camera.h>

class Race : public Object
{
    GameUpdater& _gameUpdater;

public:
    Ship Player;
    Track* Track;
    ShipController PlayerController;
    Camera Camera;

    Race(
        GameUpdater& gameUpdater);

    void Start(::Track& selectedTrack);
    void Update();
};
