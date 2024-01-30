#include <render/ui/StartMenuRenderer.h>
#include <render/ui/TrackSelectorRenderer.h>
#include <render/ui/PauseMenuRenderer.h>
#include <render/ui/GameScreenRenderer.h>
#include <render/ui/ScreenRendererCollection.h>

ScreenRendererCollection::ScreenRendererCollection()
{
    StartMenuRenderer* startMenuRenderer = new StartMenuRenderer();
    TrackSelectorRenderer* trackSelectorRenderer = new TrackSelectorRenderer();
    GameScreenRenderer* gameScreenRenderer = new GameScreenRenderer();
    PauseMenuRenderer* pauseMenuRenderer = new PauseMenuRenderer(*gameScreenRenderer);

    _renderers[(int)ScreenKind::StartMenu] = startMenuRenderer;
    _renderers[(int)ScreenKind::TrackSelector] = trackSelectorRenderer;
    _renderers[(int)ScreenKind::PauseMenu] = pauseMenuRenderer;
    _renderers[(int)ScreenKind::Game] = gameScreenRenderer;
}

ScreenRendererCollection::~ScreenRendererCollection()
{
    for (int i = 0; i < _renderers.Count; i++)
    {
        delete _renderers[i];
    }
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
