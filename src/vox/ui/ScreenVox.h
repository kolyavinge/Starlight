#pragma once

#include <lib/Object.h>
#include <ui/Screen.h>

class ScreenVox : public Object
{
public:
    virtual void Activate(Screen* prevScreen);
    virtual void Deactivate();
    virtual void Voice(Screen& screen) = 0;
};
