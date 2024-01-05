#pragma once

#include <lib/Object.h>
#include <core/Game.h>

class RenderLogic : public Object
{
public:
    virtual void Render(Game& game) = 0;
};
