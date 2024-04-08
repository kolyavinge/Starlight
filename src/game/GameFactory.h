#pragma once

#include <game/GameInitializer.h>
#include <game/Game.h>

class GameFactory
{
public:
    static GameInitializer MakeGameInitializer();
    static Game& MakeNewGame();
};
