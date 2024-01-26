#pragma once

#include <lib/Object.h>
#include <model/Ship.h>
#include <model/Track.h>
#include <core/GameUpdater.h>
#include <core/ShipController.h>
#include <core/Camera.h>

class Game : public Object
{
    inline static EmptyGameUpdater _emptyGameUpdater;

    GameUpdater& _gameUpdater;
    IGameUpdater* _currentGameUpdater;
    bool _isPaused;

public:
    Ship& Player;
    Track& Track;
    ShipController& PlayerController;
    Camera& Camera;

    Game(
        Ship& player,
        ::Track& track,
        GameUpdater& gameUpdater,
        ShipController& controller,
        ::Camera& camera);

    void Update();
    void SwitchPause();
};
