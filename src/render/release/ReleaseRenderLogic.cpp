#include <render/release/ReleaseRenderLogic.h>

void ReleaseRenderLogic::Render(Game& game)
{
    _backgroundRenderer.Render();
    _trackRenderer.Render(game.CurrentTrack);
    _shipRenderer.Render(game.Player);
}
