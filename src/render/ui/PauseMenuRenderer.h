#pragma once

#include <ui/Screen.h>
#include <ui/PauseMenuScreen.h>
#include <gl/TexturedRect.h>
#include <render/ui/SelectedItemColor.h>
#include <render/ui/GraphicItemCollection.h>
#include <render/ui/ScreenRenderer.h>
#include <render/ui/RaceRenderer.h>

class PauseMenuRenderer : public ScreenRenderer
{
    TexturedRect* _pauseItem;
    TexturedRect* _resumeItem;
    TexturedRect* _startMenuItem;
    RaceRenderer& _raceRenderer;
    SelectedItemColor _selectedItemColor;

public:
    PauseMenuRenderer(RaceRenderer& raceRenderer);

    void Init(GraphicItemCollection& graphicItemCollection) override;
    void Render(Screen& screen) override;

private:
    void RenderMenu(PauseMenuScreen& screen);
    void RenderDarkBackground();
};
