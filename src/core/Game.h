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
    Controller& PlayerController;
    //Ship Player;
    //Track Track;

    Game(
        GameUpdater& gameUpdater,
        Controller& controller);

    void Update();
};
