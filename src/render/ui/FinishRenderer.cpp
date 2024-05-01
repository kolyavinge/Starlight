#include <gl/opengl.h>
#include <core/Constants.h>
#include <ui/FinishScreen.h>
#include <render/ui/FinishRenderer.h>

FinishRenderer::FinishRenderer(
    Camera& camera,
    Race& race,
    BackgroundRenderer& backgroundRenderer,
    StarsRenderer& starsRenderer,
    ShipsRenderer& shipsRenderer,
    TrackRenderer& trackRenderer,
    BulletsRenderer& bulletsRenderer,
    EnemyShipsHealthRenderer& enemyShipsHealthRenderer,
    ExplosionRenderer& explosionRenderer,
    PowerUpRenderer& powerUpRenderer,
    FinishDashboardRenderer& dashboardRenderer,
    FinishTextRenderer& finishTextRenderer) :
    _camera(camera),
    _race(race),
    _backgroundRenderer(backgroundRenderer),
    _starsRenderer(starsRenderer),
    _shipsRenderer(shipsRenderer),
    _trackRenderer(trackRenderer),
    _bulletsRenderer(bulletsRenderer),
    _enemyShipsHealthRenderer(enemyShipsHealthRenderer),
    _explosionRenderer(explosionRenderer),
    _powerUpRenderer(powerUpRenderer),
    _dashboardRenderer(dashboardRenderer),
    _finishTextRenderer(finishTextRenderer),
    _fadeEffect(FadeDirection::ToBlack, 100)
{
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

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();
    gluPerspective(_camera.ViewAngleDegrees, Constants::ScreenAspect, 0.1, Constants::SceneRadiusDouble);
    gluLookAt(_camera.Position, _camera.LookAt, Constants::UpAxis);
    _backgroundRenderer.Render();
    _starsRenderer.Render();
    _trackRenderer.Render();
    _shipsRenderer.Render(_race.Player, _race.Enemies);
    _bulletsRenderer.Render(_race.Player, _race.Enemies);
    _explosionRenderer.Render(_race.Player, _race.AllShips);
    _powerUpRenderer.Render(_race.PowerUps);

    glLoadIdentity();
    glOrtho(0.0, Constants::ScreenWidth, 0.0, Constants::ScreenHeight, -100.0, 100.0);
    glEnable(GL_BLEND);
    _dashboardRenderer.Render(_race.Player, _race.Laps);
    _finishTextRenderer.Render();
    _fadeEffect.Render();
    glDisable(GL_BLEND);
}

void FinishRenderer::Update()
{
    _powerUpRenderer.Update();
}

FinishRenderer* FinishRendererResolvingFactory::Make(Resolver& resolver)
{
    return new FinishRenderer(
        resolver.Resolve<Camera>(),
        resolver.Resolve<Race>(),
        resolver.Resolve<BackgroundRenderer>(),
        resolver.Resolve<StarsRenderer>(),
        resolver.Resolve<ShipsRenderer>(),
        resolver.Resolve<TrackRenderer>(),
        resolver.Resolve<BulletsRenderer>(),
        resolver.Resolve<EnemyShipsHealthRenderer>(),
        resolver.Resolve<ExplosionRenderer>(),
        resolver.Resolve<PowerUpRenderer>(),
        resolver.Resolve<FinishDashboardRenderer>(),
        resolver.Resolve<FinishTextRenderer>());
}
