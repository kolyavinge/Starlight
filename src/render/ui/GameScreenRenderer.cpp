#include <gl/opengl.h>
#include <core/Constants.h>
#include <core/Race.h>
#include <ui/GameScreen.h>
#include <render/ui/GameScreenRenderer.h>

void GameScreenRenderer::Init()
{
    _backgroundRenderer.Init();
    _shipRenderer.Init();
}

void GameScreenRenderer::Render(Screen& screen)
{
    GameScreen& gameScreen = (GameScreen&)screen;
    Race& race = gameScreen.Race;
    Render(race);
}

void GameScreenRenderer::Render(Race& race)
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
