#pragma once

#include <lib/Object.h>
#include <core/Game.h>

class GameInitializer : Object
{
public:
    void Init(Game& game);

private:
    void SetPlayerByStartFinishLine(Game& game);
    void UpdateShipPosition(Game& game);
};
