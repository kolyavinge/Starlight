#include <ui/RacePreparationScreen.h>
#include <gl/opengl.h>
#include <render/ui/RacePreparationRenderer.h>

RacePreparationRenderer::RacePreparationRenderer(
    Camera& camera,
    Race& race,
    BackgroundRenderer& backgroundRenderer,
    StarsRenderer& starsRenderer,
    ShipsRenderer& shipsRenderer,
    TrackRenderer& trackRenderer,
    PowerUpRenderer& powerUpRenderer,
    CountdownRenderer& countdownRenderer) :
    _camera(camera),
    _race(race),
    _backgroundRenderer(backgroundRenderer),
    _starsRenderer(starsRenderer),
    _shipsRenderer(shipsRenderer),
    _trackRenderer(trackRenderer),
    _powerUpRenderer(powerUpRenderer),
    _countdownRenderer(countdownRenderer),
    _fadeEffect(FadeDirection::ToTransparent, 100)
{
}

void RacePreparationRenderer::Activate(Screen*)
{
    _trackRenderer.Init(*_race.Track);
    _fadeEffect.Reset();
    _fadeEffect.Activate();
}

void RacePreparationRenderer::Render(Screen& screen)
{
    RacePreparationScreen& racePreparationScreen = (RacePreparationScreen&)screen;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();
    gluPerspective(_camera.ViewAngleDegrees, Constants::ScreenAspect, 0.1, Constants::SceneRadiusDouble);
    gluLookAt(_camera.Position, _camera.LookAt, Constants::UpAxis);
    _backgroundRenderer.Render();
    _starsRenderer.Render();
    _trackRenderer.Render();
    _shipsRenderer.RenderAllShips(_race.Player, _race.Enemies);
    _powerUpRenderer.Render(_race.PowerUps);

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

void RacePreparationRenderer::Update()
{
    _shipsRenderer.Update();
    _powerUpRenderer.Update();
}

RacePreparationRenderer* RacePreparationRendererResolvingFactory::Make(Resolver& resolver)
{
    return new RacePreparationRenderer(
        resolver.Resolve<Camera>(),
        resolver.Resolve<Race>(),
        resolver.Resolve<BackgroundRenderer>(),
        resolver.Resolve<StarsRenderer>(),
        resolver.Resolve<ShipsRenderer>(),
        resolver.Resolve<TrackRenderer>(),
        resolver.Resolve<PowerUpRenderer>(),
        resolver.Resolve<CountdownRenderer>());
}
