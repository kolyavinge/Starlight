#pragma once

#include <lib/Object.h>
#include <lib/Array.h>
#include <lib/di/ResolvingFactory.h>
#include <ui/Screen.h>
#include <render/ui/ScreenRenderer.h>
#include <render/ui/StartMenuRenderer.h>
#include <render/ui/TrackSelectorRenderer.h>
#include <render/ui/RacePreparationRenderer.h>
#include <render/ui/RaceRenderer.h>
#include <render/ui/PauseMenuRenderer.h>
#include <render/ui/FinishRenderer.h>

class ScreenRendererCollection : public Object
{
    StartMenuRenderer& _startMenuRenderer;
    TrackSelectorRenderer& _trackSelectorRenderer;
    RacePreparationRenderer& _racePreparationRenderer;
    RaceRenderer& _raceRenderer;
    PauseMenuRenderer& _pauseMenuRenderer;
    FinishRenderer& _finishRenderer;

    Array<ScreenRenderer*, 6> _renderers;

public:
    ScreenRendererCollection(
        StartMenuRenderer& startMenuRenderer,
        TrackSelectorRenderer& trackSelectorRenderer,
        RacePreparationRenderer& racePreparationRenderer,
        RaceRenderer& raceRenderer,
        PauseMenuRenderer& pauseMenuRenderer,
        FinishRenderer& finishRenderer);

    ScreenRenderer& GetScreenRenderer(Screen& screen);
};

class ScreenRendererCollectionResolvingFactory : public ResolvingFactory<ScreenRendererCollection>
{
public:
    ScreenRendererCollection* Make(Resolver& resolver) override;
};
