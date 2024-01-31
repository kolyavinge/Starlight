#pragma once

#include <lib/Object.h>
#include <core/Game.h>

class ScreenRenderer : public Object
{
public:
    virtual void Init() = 0;
    virtual void Render(Game& game) = 0;
};
