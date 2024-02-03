#pragma once

#include <calc/SinPeriodValue.h>
#include <ui/Screen.h>
#include <gl/TexturedRect.h>
#include <ui/PauseMenuScreen.h>
#include <render/ui/ScreenRenderer.h>
#include <render/ui/GameScreenRenderer.h>

class PauseMenuRenderer : public ScreenRenderer
{
    TexturedRect _pauseItem;
    TexturedRect _resumeItem;
    TexturedRect _startMenuItem;
    GameScreenRenderer& _gameScreenRenderer;
    SinPeriodValue _selectedItemAlpha;

public:
    PauseMenuRenderer(GameScreenRenderer& gameScreenRenderer);

    void Init() override;
    void Render(Screen& screen) override;

private:
    void RenderMenu(PauseMenuScreen& screen);
    void RenderDarkBackground();
    void SetAlphaForSelectedItem(PauseMenuScreen& screen, PauseMenuItem item);
};
