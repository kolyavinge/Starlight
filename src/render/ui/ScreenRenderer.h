#pragma once

#include <lib/Object.h>
#include <ui/Screen.h>

class ScreenRenderer : public Object
{
public:
    virtual void Init() = 0;
    virtual void Render(Screen& screen) = 0;
};
