#include <gl/opengl.h>
#include <core/Constants.h>
#include <ui/FinishScreen.h>
#include <render/ui/FinishRenderer.h>

FinishRenderer::FinishRenderer(
    RaceRenderer& raceRenderer) :
    _raceRenderer(raceRenderer),
    _fadeEffect(FadeDirection::ToBlack, 100)
{
}

void FinishRenderer::Init(GraphicItemCollection&)
{
    _finishTextRenderer.Init();
}

void FinishRenderer::Activate(Screen*)
{
    _fadeEffect.Reset();
}

void FinishRenderer::Render(Screen& screen)
{
    FinishScreen& finishScreen = (FinishScreen&)screen;
    if (finishScreen.IterationsCount - finishScreen.GetCurrentIteration() == 150)
    {
        _fadeEffect.Activate();
    }
    _raceRenderer.Render(finishScreen.Race);
    glLoadIdentity();
    glOrtho(0.0, Constants::ScreenWidth, 0.0, Constants::ScreenHeight, -100.0, 100.0);
    glEnable(GL_BLEND);
    _finishTextRenderer.Render();
    _fadeEffect.Render();
    glDisable(GL_BLEND);
}