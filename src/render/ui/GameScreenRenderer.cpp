#include <render/ui/GameScreenRenderer.h>

void GameScreenRenderer::Init()
{
    _backgroundRenderer.Init();
    _shipRenderer.Init();
}

void GameScreenRenderer::Render(Game& game)
{
    _backgroundRenderer.Render();
    _starsRenderer.Render();
    _trackRenderer.Render(game.Track);
    _shipRenderer.Render(game.Player);
}
