#include <gl/opengl.h>
#include <core/Constants.h>
#include <render/common/DashboardRenderer.h>

DashboardRenderer::DashboardRenderer(TextRenderer& textRenderer) :
    _lapsCountRenderer(textRenderer),
    _lapTimeRenderer(textRenderer)
{
}

void DashboardRenderer::Render(Laps& laps)
{
    glLoadIdentity();
    gluOrtho2D(0.0, Constants::ScreenWidth, 0.0, Constants::ScreenHeight);
    glEnable(GL_BLEND);
    _lapsCountRenderer.Render(laps);
    _lapTimeRenderer.Render(laps);
    glDisable(GL_BLEND);
}
