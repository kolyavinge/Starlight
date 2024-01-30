#pragma once

#include <calc/SinPeriodValue.h>
#include <core/Game.h>
#include <gl/TexturedRect.h>
#include <ui/StartMenuScreen.h>
#include <render/common/MenuBackgroundRenderer.h>
#include <render/ui/ScreenRenderer.h>

class StartMenuRenderer : public ScreenRenderer
{
    MenuBackgroundRenderer _backgroundRenderer;
    TexturedRect _startGameItem;
    TexturedRect _exitItem;
    SinPeriodValue _selectedItemAlpha;

public:
    void Init() override;
    void Render(Game& game) override;

private:
    void RenderMenu(StartMenuScreen& screen);
    void SetAlphaForSelectedItem(StartMenuScreen& screen, StartMenuItem item);
};
