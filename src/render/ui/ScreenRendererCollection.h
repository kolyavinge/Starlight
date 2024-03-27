#pragma once

#include <lib/Object.h>
#include <lib/Array.h>
#include <lib/di/ResolvingFactory.h>
#include <ui/Screen.h>
#include <gl/TextRenderer.h>
#include <render/common/BackgroundRenderer.h>
#include <render/common/MenuBackgroundRenderer.h>
#include <render/common/StarsRenderer.h>
#include <render/common/ShipsRenderer.h>
#include <render/common/TrackRenderer.h>
#include <render/common/BulletsRenderer.h>
#include <render/common/EnemyShipsHealthRenderer.h>
#include <render/common/ExplosionRenderer.h>
#include <render/common/PowerUpRenderer.h>
#include <render/dash/DashboardRenderer.h>
#include <render/ui/GraphicItemCollection.h>
#include <render/ui/ScreenRenderer.h>
#include <render/ui/StartMenuRenderer.h>
#include <render/ui/TrackSelectorRenderer.h>
#include <render/ui/RacePreparationRenderer.h>
#include <render/ui/RaceRenderer.h>
#include <render/ui/PauseMenuRenderer.h>
#include <render/ui/FinishRenderer.h>

class ScreenRendererCollection : public Object
{
    TextRenderer _textRenderer;
    BackgroundRenderer _backgroundRenderer;
    StarsRenderer _starsRenderer;
    MenuBackgroundRenderer _menuBackgroundRenderer;
    ShipsRenderer _shipsRenderer;
    TrackRenderer _trackRenderer;
    BulletsRenderer _bulletsRenderer;
    EnemyShipsHealthRenderer _enemyShipsHealthRenderer;
    ExplosionRenderer _explosionRenderer;
    PowerUpRenderer _powerUpRenderer;
    DashboardRenderer _dashboardRenderer;

    GraphicItemCollection _graphicItemCollection;

    StartMenuRenderer _startMenuRenderer;
    TrackSelectorRenderer _trackSelectorRenderer;
    RacePreparationRenderer _racePreparationRenderer;
    RaceRenderer _raceRenderer;
    PauseMenuRenderer _pauseMenuRenderer;
    FinishRenderer _finishRenderer;

    Array<ScreenRenderer*, 6> _renderers;

public:
    ScreenRendererCollection();

    void Init();
    ScreenRenderer& GetScreenRenderer(Screen& screen);
};

class ScreenRendererCollectionResolvingFactory : public ResolvingFactory<ScreenRendererCollection>
{
public:
    ScreenRendererCollection* Make(Resolver& resolver) override;
};
