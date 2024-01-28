#pragma once

#include <lib/Object.h>
#include <core/Game.h>

class ScreenRenderer : public Object
{
public:
    virtual void Init();
    virtual void Render(Game& game) = 0;
};
