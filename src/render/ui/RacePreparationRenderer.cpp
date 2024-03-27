#include <gl/opengl.h>
#include <core/Race.h>
#include <ui/RacePreparationScreen.h>
#include <render/ui/RacePreparationRenderer.h>

RacePreparationRenderer::RacePreparationRenderer(
    BackgroundRenderer& backgroundRenderer,
    StarsRenderer& starsRenderer,
    ShipsRenderer& shipsRenderer,
    TrackRenderer& trackRenderer,
    CountdownRenderer& countdownRenderer) :
    _backgroundRenderer(backgroundRenderer),
    _starsRenderer(starsRenderer),
    _shipsRenderer(shipsRenderer),
    _trackRenderer(trackRenderer),
    _countdownRenderer(countdownRenderer),
    _fadeEffect(FadeDirection::ToTransparent, 100)
{
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
    _shipsRenderer.Render(race.Player, race.Enemies);

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

RacePreparationRenderer* RacePreparationRendererResolvingFactory::Make(Resolver& resolver)
{
    return new RacePreparationRenderer(
        resolver.Resolve<BackgroundRenderer>(),
        resolver.Resolve<StarsRenderer>(),
        resolver.Resolve<ShipsRenderer>(),
        resolver.Resolve<TrackRenderer>(),
        resolver.Resolve<CountdownRenderer>());
}
