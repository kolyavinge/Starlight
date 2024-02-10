#include <gl/opengl.h>
#include <render/common/DashboardRenderer.h>

DashboardRenderer::DashboardRenderer(TextRenderer& textRenderer) :
    _lapsCountRenderer(textRenderer),
    _lapTimeRenderer(textRenderer)
{
}

void DashboardRenderer::Render(Laps& laps)
{
    _lapsCountRenderer.Render(laps);
    _lapTimeRenderer.Render(laps);
}
