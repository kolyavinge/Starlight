#pragma once

#include <lib/Object.h>
#include <gl/TexturedRect.h>

class MenuItemCollection : public Object
{
public:
    TexturedRect StartGameItem;
    TexturedRect ExitItem;
    TexturedRect PauseItem;
    TexturedRect ResumeItem;
    TexturedRect StartMenuItem;

    void Init();
};
