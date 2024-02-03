#include <gl/opengl.h>
#include <core/Constants.h>
#include <core/Race.h>
#include <ui/RaceScreen.h>
#include <render/ui/RaceRenderer.h>

void RaceRenderer::Init()
{
    _backgroundRenderer.Init();
    _shipRenderer.Init();
}

void RaceRenderer::Render(Screen& screen)
{
    RaceScreen& gameScreen = (RaceScreen&)screen;
    Race& race = gameScreen.Race;
    Render(race);
}

void RaceRenderer::Render(Race& race)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(race.Camera.ViewAngle, Constants::ScreenAspect, 0.1, Constants::SceneRadiusDouble);
    gluLookAt(race.Camera.Position, race.Camera.LookAt, Constants::UpAxis);
    //gluLookAt(0, 2000, 100, 0, 0, 0, 0, 0, 1);
    _backgroundRenderer.Render();
    _starsRenderer.Render();
    _trackRenderer.Render(*race.Track);
    _shipRenderer.Render(race.Player);
}
