#include <render/release/ReleaseRenderLogic.h>

void ReleaseRenderLogic::Init()
{
    _backgroundRenderer.Init();
}

void ReleaseRenderLogic::Render(Game& game)
{
    _backgroundRenderer.Render();
    _trackRenderer.Render(game.CurrentTrack);
    _shipRenderer.Render(game.Player);
}
