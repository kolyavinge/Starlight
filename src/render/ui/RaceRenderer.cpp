#include <gl/opengl.h>
#include <core/Constants.h>
#include <core/Race.h>
#include <ui/RaceScreen.h>
#include <render/ui/RaceRenderer.h>

RaceRenderer::RaceRenderer(
    BackgroundRenderer& backgroundRenderer,
    StarsRenderer& starsRenderer,
    ShipRenderer& shipRenderer,
    TrackRenderer& trackRenderer,
    DashboardRenderer& dashboardRenderer) :
    _backgroundRenderer(backgroundRenderer),
    _starsRenderer(starsRenderer),
    _shipRenderer(shipRenderer),
    _trackRenderer(trackRenderer),
    _dashboardRenderer(dashboardRenderer)
{
}

void RaceRenderer::Init(GraphicItemCollection&)
{
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
    //gluLookAt(0, 2000, 100, 0, 0, 0, 0, 0, 1);
    _backgroundRenderer.Render();
    _starsRenderer.Render();
    _trackRenderer.Render(*race.Track);
    _shipRenderer.Render(race.Player);
    _dashboardRenderer.Render(race.Laps);
}
