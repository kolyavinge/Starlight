#pragma once

#include <lib/Object.h>
#include <ui/Screen.h>
#include <render/ui/GraphicItemCollection.h>

class ScreenRenderer : public Object
{
public:
    virtual void Init(GraphicItemCollection& graphicItemCollection);
    virtual void Activate(Screen* prevScreen);
    virtual void Deactivate();
    virtual void Render(Screen& screen) = 0;
};
