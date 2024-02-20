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

void RacePreparationRenderer::Init(GraphicItemCollection& graphicItemCollection)
{
    _countdownRenderer.Init(
        graphicItemCollection.Countdown1Item,
        graphicItemCollection.Countdown2Item,
        graphicItemCollection.Countdown3Item);
}

void RacePreparationRenderer::Activate(Screen*)
{
    _fadeEffect.Reset();
    _fadeEffect.Activate();
}

void RacePreparationRenderer::Render(Screen& screen)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();
    RacePreparationScreen& racePreparationScreen = (RacePreparationScreen&)screen;
    Race& race = racePreparationScreen.Race;
    gluPerspective(race.Camera.ViewAngleDegrees, Constants::ScreenAspect, 0.1, Constants::SceneRadiusDouble);
    gluLookAt(race.Camera.Position, race.Camera.LookAt, Constants::UpAxis);
    _backgroundRenderer.Render();
    _starsRenderer.Render();
    _trackRenderer.Render(*race.Track);
    _shipRenderer.Render(race.Player);
    for (int i = 0; i < race.Enemies.Count(); i++)
    {
        _shipRenderer.Render(race.Enemies[i]);
    }

    glEnable(GL_BLEND);
    _fadeEffect.Render();
    glLoadIdentity();
    gluOrtho2D(0.0, Constants::ScreenWidth, 0.0, Constants::ScreenHeight);
    _countdownRenderer.Render(
        racePreparationScreen.GetCountdownNumber(),
        racePreparationScreen.GetCountdownIteration(),
        racePreparationScreen.GetCountdownSwitchIteration());
    glDisable(GL_BLEND);
}
