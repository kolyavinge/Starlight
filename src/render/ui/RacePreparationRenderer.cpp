#include <gl/opengl.h>
#include <core/Race.h>
#include <ui/RacePreparationScreen.h>
#include <render/ui/RacePreparationRenderer.h>

RacePreparationRenderer::RacePreparationRenderer(
    BackgroundRenderer& backgroundRenderer,
    StarsRenderer& starsRenderer,
    ShipRenderer& shipRenderer,
    TrackRenderer& trackRenderer) :
    _backgroundRenderer(backgroundRenderer),
    _starsRenderer(starsRenderer),
    _shipRenderer(shipRenderer),
    _trackRenderer(trackRenderer),
    _fadeEffect(FadeDirection::ToTransparent, 100)
{
}

void RacePreparationRenderer::Init(MenuItemCollection&)
{
}

void RacePreparationRenderer::Activate()
{
    _fadeEffect.Reset();
    _fadeEffect.Activate();
}

void RacePreparationRenderer::Render(Screen& screen)
{
    RacePreparationScreen& racePreparationScreen = (RacePreparationScreen&)screen;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    Race& race = racePreparationScreen.Race;
    gluPerspective(race.Camera.ViewAngleDegrees, Constants::ScreenAspect, 0.1, Constants::SceneRadiusDouble);
    gluLookAt(race.Camera.Position, race.Camera.LookAt, Constants::UpAxis);
    _backgroundRenderer.Render();
    _starsRenderer.Render();
    _trackRenderer.Render(*race.Track);
    _shipRenderer.Render(race.Player);
    glEnable(GL_BLEND);
    _fadeEffect.Render();
    glDisable(GL_BLEND);
}
