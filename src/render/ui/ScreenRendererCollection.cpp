#include <render/ui/StartMenuRenderer.h>
#include <render/ui/TrackSelectorRenderer.h>
#include <render/ui/PauseMenuRenderer.h>
#include <render/ui/GameScreenRenderer.h>
#include <render/ui/ScreenRendererCollection.h>

ScreenRendererCollection::ScreenRendererCollection()
{
    _renderers[ScreenKind::StartMenuKind] = new StartMenuRenderer();
    _renderers[ScreenKind::TrackSelectorKind] = new TrackSelectorRenderer();
    _renderers[ScreenKind::PauseMenuKind] = new PauseMenuRenderer();
    _renderers[ScreenKind::GameKind] = new GameScreenRenderer();
}

ScreenRendererCollection::~ScreenRendererCollection()
{
    delete _renderers[ScreenKind::StartMenuKind];
    delete _renderers[ScreenKind::TrackSelectorKind];
    delete _renderers[ScreenKind::PauseMenuKind];
    delete _renderers[ScreenKind::GameKind];
}

void ScreenRendererCollection::Init()
{
    for (int i = 0; i < _renderers.Count; i++)
    {
        _renderers[i]->Init();
    }
}

ScreenRenderer& ScreenRendererCollection::GetScreenRenderer(Screen& screen)
{
    return *_renderers[screen.Kind];
}
