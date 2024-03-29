#pragma once

#include <lib/di/ResolvingFactory.h>
#include <ui/Screen.h>
#include <ui/PauseMenuScreen.h>
#include <gl/TexturedRect.h>
#include <render/ui/SelectedItemColor.h>
#include <render/ui/ScreenRenderer.h>
#include <render/ui/RaceRenderer.h>

class PauseMenuRenderer : public ScreenRenderer
{
    RaceRenderer& _raceRenderer;
    TexturedRect& _pauseItem;
    TexturedRect& _resumeItem;
    TexturedRect& _startMenuItem;
    SelectedItemColor _selectedItemColor;

public:
    PauseMenuRenderer(
        GraphicItemCollection& graphicItemCollection,
        RaceRenderer& raceRenderer);

    void Render(Screen& screen) override;

private:
    void RenderMenu(PauseMenuScreen& screen);
    void RenderDarkBackground();
};

class PauseMenuRendererResolvingFactory : public ResolvingFactory<PauseMenuRenderer>
{
public:
    PauseMenuRenderer* Make(Resolver& resolver) override;
};
