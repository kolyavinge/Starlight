#pragma once

#include <lib/Object.h>
#include <lib/Array.h>
#include <ui/Screen.h>
#include <gl/TextRenderer.h>
#include <render/common/BackgroundRenderer.h>
#include <render/common/MenuBackgroundRenderer.h>
#include <render/common/StarsRenderer.h>
#include <render/common/ShipRenderer.h>
#include <render/common/TrackRenderer.h>
#include <render/common/DashboardRenderer.h>
#include <render/ui/GraphicItemCollection.h>
#include <render/ui/ScreenRenderer.h>
#include <render/ui/StartMenuRenderer.h>
#include <render/ui/TrackSelectorRenderer.h>
#include <render/ui/RacePreparationRenderer.h>
#include <render/ui/RaceRenderer.h>
#include <render/ui/PauseMenuRenderer.h>

class ScreenRendererCollection : public Object
{
    TextRenderer _textRenderer;
    BackgroundRenderer _backgroundRenderer;
    StarsRenderer _starsRenderer;
    MenuBackgroundRenderer _menuBackgroundRenderer;
    ShipRenderer _shipRenderer;
    TrackRenderer _trackRenderer;
    DashboardRenderer _dashboardRenderer;

    GraphicItemCollection _graphicItemCollection;

    StartMenuRenderer _startMenuRenderer;
    TrackSelectorRenderer _trackSelectorRenderer;
    RacePreparationRenderer _racePreparationRenderer;
    RaceRenderer _raceRenderer;
    PauseMenuRenderer _pauseMenuRenderer;

    Array<ScreenRenderer*, 5> _renderers;

public:
    ScreenRendererCollection();

    void Init();
    ScreenRenderer& GetScreenRenderer(Screen& screen);
};
