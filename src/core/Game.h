#pragma once

#include "lib/Object.h"
#include "model/Ship.h"
#include "model/Track.h"
#include "core/GameUpdater.h"
#include "core/Controller.h"

class Game : public Object
{
    GameUpdater& _gameUpdater;

public:
    Ship& Player;
    Track& CurrentTrack;
    Controller& PlayerController;

    Game(
        Ship& player,
        Track& track,
        GameUpdater& gameUpdater,
        Controller& controller);

    void Update();
};
