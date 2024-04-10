#include <gl/TextRenderer.h>
#include <render/common/BackgroundRenderer.h>
#include <render/common/BulletsRenderer.h>
#include <render/common/CountdownRenderer.h>
#include <render/common/EnemyShipsHealthRenderer.h>
#include <render/common/ExplosionRenderer.h>
#include <render/common/FinishTextRenderer.h>
#include <render/common/GoRenderer.h>
#include <render/common/GraphicItemCollection.h>
#include <render/common/MenuBackgroundRenderer.h>
#include <render/common/PowerUpRenderer.h>
#include <render/common/ShipMesh.h>
#include <render/common/ShipRenderer.h>
#include <render/common/ShipsRenderer.h>
#include <render/common/StarsRenderer.h>
#include <render/common/TrackRenderer.h>
#include <render/common/TrackThumbnailGridRenderer.h>
#include <render/common/TrackThumbnailRenderer.h>
#include <render/dash/BulletsCountRenderer.h>
#include <render/dash/CompleteLapsTimeListRenderer.h>
#include <render/dash/CompleteLapTimeRenderer.h>
#include <render/dash/DashboardRenderer.h>
#include <render/dash/LapsCountRenderer.h>
#include <render/dash/LapTimeRenderer.h>
#include <render/dash/NitroCountRenderer.h>
#include <render/dash/PlayerShipHealthRenderer.h>
#include <render/ui/FinishRenderer.h>
#include <render/ui/PauseMenuRenderer.h>
#include <render/ui/RacePreparationRenderer.h>
#include <render/ui/RaceRenderer.h>
#include <render/ui/RenderManager.h>
#include <render/ui/StartMenuRenderer.h>
#include <render/ui/TrackSelectorRenderer.h>
#include <game/inject/RenderInjectModule.h>

void RenderInjectModule::Init(Binder& binder)
{
    binder.BindSingletonByFactory<TextRenderer, TextRendererResolvingFactory>();
    binder.BindSingletonByFactory<BackgroundRenderer, BackgroundRendererResolvingFactory>();
    binder.BindSingletonByFactory<BulletsRenderer, BulletsRendererResolvingFactory>();
    binder.BindSingletonByFactory<CountdownRenderer, CountdownRendererResolvingFactory>();
    binder.BindSingletonByFactory<EnemyShipsHealthRenderer, EnemyShipsHealthRendererResolvingFactory>();
    binder.BindSingletonByFactory<ExplosionRenderer, ExplosionRendererResolvingFactory>();
    binder.BindSingletonByFactory<FinishTextRenderer, FinishTextRendererResolvingFactory>();
    binder.BindSingletonByFactory<GoRenderer, GoRendererResolvingFactory>();
    binder.BindSingletonByFactory<MenuBackgroundRenderer, MenuBackgroundRendererResolvingFactory>();
    binder.BindSingletonByFactory<PowerUpRenderer, PowerUpRendererResolvingFactory>();
    binder.BindSingletonByFactory<ShipMesh, ShipMeshResolvingFactory>();
    binder.BindSingletonByFactory<ShipRenderer, ShipRendererResolvingFactory>();
    binder.BindSingletonByFactory<ShipsRenderer, ShipsRendererResolvingFactory>();
    binder.BindSingletonByFactory<StarsRenderer, StarsRendererResolvingFactory>();
    binder.BindSingletonByFactory<TrackRenderer, TrackRendererResolvingFactory>();
    binder.BindSingletonByFactory<TrackThumbnailGridRenderer, TrackThumbnailGridRendererResolvingFactory>();
    binder.BindSingletonByFactory<TrackThumbnailRenderer, TrackThumbnailRendererResolvingFactory>();
    binder.BindSingletonByFactory<BulletsCountRenderer, BulletsCountRendererResolvingFactory>();
    binder.BindSingletonByFactory<CompleteLapsTimeListRenderer, CompleteLapsTimeListRendererResolvingFactory>();
    binder.BindSingletonByFactory<CompleteLapTimeRenderer, CompleteLapTimeRendererResolvingFactory>();
    binder.BindSingletonByFactory<DashboardRenderer, DashboardRendererResolvingFactory>();
    binder.BindSingletonByFactory<LapsCountRenderer, LapsCountRendererResolvingFactory>();
    binder.BindSingletonByFactory<LapTimeRenderer, LapTimeRendererResolvingFactory>();
    binder.BindSingletonByFactory<NitroCountRenderer, NitroCountRendererResolvingFactory>();
    binder.BindSingletonByFactory<PlayerShipHealthRenderer, PlayerShipHealthRendererResolvingFactory>();
    binder.BindSingletonByFactory<FinishRenderer, FinishRendererResolvingFactory>();
    binder.BindSingletonByFactory<GraphicItemCollection, GraphicItemCollectionResolvingFactory>();
    binder.BindSingletonByFactory<PauseMenuRenderer, PauseMenuRendererResolvingFactory>();
    binder.BindSingletonByFactory<RacePreparationRenderer, RacePreparationRendererResolvingFactory>();
    binder.BindSingletonByFactory<RaceRenderer, RaceRendererResolvingFactory>();
    binder.BindSingletonByFactory<RenderManager, RenderManagerResolvingFactory>();
    binder.BindSingletonByFactory<StartMenuRenderer, StartMenuRendererResolvingFactory>();
    binder.BindSingletonByFactory<TrackSelectorRenderer, TrackSelectorRendererResolvingFactory>();
}
