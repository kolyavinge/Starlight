#pragma once

#include <calc/SinPeriodValue.h>
#include <ui/Screen.h>
#include <gl/TexturedRect.h>
#include <ui/StartMenuScreen.h>
#include <render/common/MenuBackgroundRenderer.h>
#include <render/ui/MenuItemCollection.h>
#include <render/ui/ScreenRenderer.h>

class StartMenuRenderer : public ScreenRenderer
{
    MenuBackgroundRenderer _backgroundRenderer;
    TexturedRect* _startGameItem;
    TexturedRect* _exitItem;
    SinPeriodValue _selectedItemAlpha;

public:
    StartMenuRenderer();

    void Init(MenuItemCollection& menuItemCollection) override;
    void Render(Screen& screen) override;

private:
    void RenderMenu(StartMenuScreen& screen);
    void SetAlphaForSelectedItem(StartMenuScreen& screen, StartMenuItem item);
};
