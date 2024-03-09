#include <gl/opengl.h>
#include <core/Constants.h>
#include <core/Race.h>
#include <ui/RaceScreen.h>
#include <render/ui/RaceRenderer.h>

RaceRenderer::RaceRenderer(
    BackgroundRenderer& backgroundRenderer,
    StarsRenderer& starsRenderer,
    ShipsRenderer& shipsRenderer,
    TrackRenderer& trackRenderer,
    BulletsRenderer& bulletsRenderer,
    EnemyShipsHealthRenderer& enemyShipsHealthRenderer,
    ExplosionRenderer& explosionRenderer,
    DashboardRenderer& dashboardRenderer) :
    _backgroundRenderer(backgroundRenderer),
    _starsRenderer(starsRenderer),
    _shipsRenderer(shipsRenderer),
    _trackRenderer(trackRenderer),
    _bulletsRenderer(bulletsRenderer),
    _enemyShipsHealthRenderer(enemyShipsHealthRenderer),
    _explosionRenderer(explosionRenderer),
    _dashboardRenderer(dashboardRenderer)
{
}

void RaceRenderer::Init(GraphicItemCollection& graphicItemCollection)
{
    _goRenderer.Init(graphicItemCollection.GoItem);
}

void RaceRenderer::Activate(Screen* prevScreen)
{
    if (prevScreen != nullptr && prevScreen->Kind == ScreenKind::RacePreparation)
    {
        _dashboardRenderer.Init();
        _goRenderer.Reset();
    }
}

void RaceRenderer::Render(Screen& screen)
{
    RaceScreen& raceScreen = (RaceScreen&)screen;
    Race& race = raceScreen.Race;
    Render(race);
}

void RaceRenderer::Render(Race& race)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();
    gluPerspective(race.Camera.ViewAngleDegrees, Constants::ScreenAspect, 0.1, Constants::SceneRadiusDouble);
    gluLookAt(race.Camera.Position, race.Camera.LookAt, Constants::UpAxis);
    //gluLookAt(0, 0, 700, 10, 10, 0, 0, 0, 1);
    _backgroundRenderer.Render();
    _starsRenderer.Render();
    _trackRenderer.Render(*race.Track);
    _shipsRenderer.Render(race.Player, race.Enemies);
    _bulletsRenderer.Render(race.Player, race.Enemies);
    _enemyShipsHealthRenderer.Render(race.Enemies);
    _explosionRenderer.Render(race.AllShips);

    glLoadIdentity();
    gluOrtho2D(0.0, Constants::ScreenWidth, 0.0, Constants::ScreenHeight);
    glEnable(GL_BLEND);
    _goRenderer.Render();
    _dashboardRenderer.Render(race.Player, race.Laps);
    glDisable(GL_BLEND);
}
