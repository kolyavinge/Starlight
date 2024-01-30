#include <gl/opengl.h>
#include <core/Constants.h>
#include <render/ui/GameScreenRenderer.h>

void GameScreenRenderer::Init()
{
    _backgroundRenderer.Init();
    _shipRenderer.Init();
}

void GameScreenRenderer::Render(Game& game)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(game.Camera.ViewAngle, Constants::ScreenAspect, 0.1, Constants::SceneRadiusDouble);
    gluLookAt(game.Camera.Position, game.Camera.LookAt, Constants::UpAxis);
    //gluLookAt(0, 2000, 100, 0, 0, 0, 0, 0, 1);
    _backgroundRenderer.Render();
    _starsRenderer.Render();
    _trackRenderer.Render(game.Track);
    _shipRenderer.Render(game.Player);
}
