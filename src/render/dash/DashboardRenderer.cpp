#include <render/dash/DashboardRenderer.h>

DashboardRenderer::DashboardRenderer(TextRenderer& textRenderer) :
    _lapsCountRenderer(textRenderer),
    _lapTimeRenderer(textRenderer),
    _completeLapTimeRenderer(textRenderer),
    _completeLapsTimeListRenderer(textRenderer),
    _healthRenderer(textRenderer),
    _bulletsCountRenderer(textRenderer),
    _nitroCountRenderer(textRenderer)
{
}

void DashboardRenderer::Init()
{
    _completeLapTimeRenderer.Init();
}

void DashboardRenderer::Render(Ship& player, Laps& laps)
{
    _lapsCountRenderer.Render(laps);
    _lapTimeRenderer.Render(laps);
    _completeLapTimeRenderer.Render(laps);
    _completeLapsTimeListRenderer.Render(laps);
    _healthRenderer.Render(player);
    _bulletsCountRenderer.Render(player.Weapon);
    _nitroCountRenderer.Render(player.Nitros);
}

DashboardRenderer* DashboardRendererResolvingFactory::Make(Resolver& resolver)
{
    return new DashboardRenderer(resolver.Resolve<TextRenderer>());
}
