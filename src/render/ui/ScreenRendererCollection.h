#pragma once

#include <lib/Object.h>
#include <lib/Array.h>
#include <ui/Screen.h>
#include <render/ui/MenuItemCollection.h>
#include <render/ui/ScreenRenderer.h>
#include <render/ui/StartMenuRenderer.h>
#include <render/ui/TrackSelectorRenderer.h>
#include <render/ui/PauseMenuRenderer.h>
#include <render/ui/RaceRenderer.h>

class ScreenRendererCollection : public Object
{
    MenuItemCollection _menuItemCollection;
    StartMenuRenderer _startMenuRenderer;
    TrackSelectorRenderer _trackSelectorRenderer;
    RaceRenderer _raceRenderer;
    PauseMenuRenderer _pauseMenuRenderer;
    Array<ScreenRenderer*, 4> _renderers;

public:
    ScreenRendererCollection();
    ~ScreenRendererCollection();

    void Init();
    ScreenRenderer& GetScreenRenderer(Screen& screen);
};
