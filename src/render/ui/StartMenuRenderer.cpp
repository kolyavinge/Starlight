#include <gl/opengl.h>
#include <lib/Random.h>
#include <lib/Math.h>
#include <calc/Geometry.h>
#include <core/Constants.h>
#include <core/Resources.h>
#include <render/ui/StartMenuRenderer.h>

StartMenuRenderer::StartMenuRenderer()
{
    Random rand;
    _turnVector.Set(
        rand.GetFloatFromZeroToOne() - 0.5f,
        rand.GetFloatFromZeroToOne() - 0.5f,
        rand.GetFloatFromZeroToOne() - 0.5f);
    _turnDegrees = rand.GetFloatFromZeroToN(720.0f) - 360.0f;
    _selectedItemRadians = 0.0f;
}

void StartMenuRenderer::Init()
{
    _backgroundRenderer.Init();
    _startGameItem.Load(Resources::GetStartGameMenuItemFilePath(), 300.0f, 50.0f);
    _exitItem.Load(Resources::GetExitMenuItemFilePath(), 300.0f, 50.0f);
}

void StartMenuRenderer::Render(Game& game)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    RenderBackground();
    RenderMenu((StartMenuScreen&)game.GetCurrentScreen());
    _turnDegrees = Geometry::NormalizeDegrees(_turnDegrees + 0.05f);
    _selectedItemRadians = Geometry::NormalizeRadians(_selectedItemRadians + 0.05f);
}

void StartMenuRenderer::RenderBackground()
{
    glLoadIdentity();
    gluPerspective(60.0, Constants::ScreenAspect, 0.1, Constants::SceneRadiusDouble);
    gluLookAt(0.0, 0.0, 0.0, 0.0, 1.0, 0.0, Constants::UpAxis.X, Constants::UpAxis.Y, Constants::UpAxis.Z);
    glPushMatrix();
    glRotatef(_turnDegrees, _turnVector.X, _turnVector.Y, _turnVector.Z);
    _backgroundRenderer.Render();
    _starsRenderer.Render();
    glPopMatrix();
}

void StartMenuRenderer::RenderMenu(StartMenuScreen& screen)
{
    glLoadIdentity();
    glOrtho(0.0, Constants::ScreenWidth, 0.0, Constants::ScreenHeight, -1.0, 1.0);
    glEnable(GL_BLEND);

    SetAlphaForSelectedItem(screen, StartMenuItem::Exit);
    glTranslatef(Constants::ScreenWidth - _exitItem.GetWidth() - 100.0f, 50.0f, 0.0f);
    _exitItem.Render();

    SetAlphaForSelectedItem(screen, StartMenuItem::StartGame);
    glTranslatef(0.0f, 75.0f, 0.0f);
    _startGameItem.Render();

    glDisable(GL_BLEND);
}

void StartMenuRenderer::SetAlphaForSelectedItem(StartMenuScreen& screen, StartMenuItem item)
{
    const float v = 0.7f;
    if (item == screen.GetSelectedItem())
    {
        glColor4f(v, v, v, Math::Abs(Math::Sin(_selectedItemRadians)));
    }
    else
    {
        glColor4f(v, v, v, 1.0f);
    }
}
