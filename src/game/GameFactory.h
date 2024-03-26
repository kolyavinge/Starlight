#pragma once

#include <game/Game.h>

class GameFactory
{
public:
    static Game& MakeNewGame();
};
