#include <render/ui/StartMenuRenderer.h>
#include <render/ui/TrackSelectorRenderer.h>
#include <render/ui/PauseMenuRenderer.h>
#include <render/ui/GameScreenRenderer.h>
#include <render/ui/ScreenRendererCollection.h>

ScreenRendererCollection::ScreenRendererCollection()
{
    _renderers[(int)ScreenKind::StartMenu] = new StartMenuRenderer();
    _renderers[(int)ScreenKind::TrackSelector] = new TrackSelectorRenderer();
    _renderers[(int)ScreenKind::PauseMenu] = new PauseMenuRenderer();
    _renderers[(int)ScreenKind::Game] = new GameScreenRenderer();
}

ScreenRendererCollection::~ScreenRendererCollection()
{
    delete _renderers[(int)ScreenKind::StartMenu];
    delete _renderers[(int)ScreenKind::TrackSelector];
    delete _renderers[(int)ScreenKind::PauseMenu];
    delete _renderers[(int)ScreenKind::Game];
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
    return *_renderers[(int)screen.Kind];
}
