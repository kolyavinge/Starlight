#include <render/ui/RenderManager.h>
#include <render/ui/StartMenuRenderer.h>
#include <render/ui/TrackSelectorRenderer.h>
#include <render/ui/PauseMenuRenderer.h>
#include <render/ui/GameScreenRenderer.h>

RenderManager::RenderManager()
{
    _renderers[ScreenKind::StartMenuKind] = new StartMenuRenderer();
    _renderers[ScreenKind::TrackSelectorKind] = new TrackSelectorRenderer();
    _renderers[ScreenKind::PauseMenuKind] = new PauseMenuRenderer();
    _renderers[ScreenKind::GameKind] = new GameScreenRenderer();
}

RenderManager::~RenderManager()
{
    delete _renderers[ScreenKind::StartMenuKind];
    delete _renderers[ScreenKind::TrackSelectorKind];
    delete _renderers[ScreenKind::PauseMenuKind];
    delete _renderers[ScreenKind::GameKind];
}

void RenderManager::Init()
{
    for (int i = 0; i < _renderers.Count; i++)
    {
        _renderers[i]->Init();
    }
}

ScreenRenderer& RenderManager::GetScreenRenderer(Screen& screen)
{
    return *_renderers[screen.Kind];
}
