#pragma once

#include <calc/SinPeriodValue.h>
#include <ui/Screen.h>
#include <gl/TexturedRect.h>
#include <ui/PauseMenuScreen.h>
#include <render/ui/ScreenRenderer.h>
#include <render/ui/RaceRenderer.h>

class PauseMenuRenderer : public ScreenRenderer
{
    TexturedRect _pauseItem;
    TexturedRect _resumeItem;
    TexturedRect _startMenuItem;
    RaceRenderer& _raceRenderer;
    SinPeriodValue _selectedItemAlpha;

public:
    PauseMenuRenderer(RaceRenderer& raceRenderer);

    void Init() override;
    void Render(Screen& screen) override;

private:
    void RenderMenu(PauseMenuScreen& screen);
    void RenderDarkBackground();
    void SetAlphaForSelectedItem(PauseMenuScreen& screen, PauseMenuItem item);
};
