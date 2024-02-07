#pragma once

#include <lib/Object.h>
#include <ui/Screen.h>
#include <render/ui/MenuItemCollection.h>

class ScreenRenderer : public Object
{
public:
    virtual void Init(MenuItemCollection& menuItemCollection);
    virtual void Activate();
    virtual void Render(Screen& screen) = 0;
};
