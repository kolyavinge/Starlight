#include <gl/opengl.h>
#include <core/Constants.h>
#include <core/Resources.h>
#include <ui/StartMenuScreen.h>
#include <render/ui/StartMenuRenderer.h>

void StartMenuRenderer::Init()
{
    _backgroundRenderer.Init();
    _startGameItem.Load(Resources::GetStartGameMenuItemFilePath(), 300.0f, 50.0f);
    _exitItem.Load(Resources::GetExitMenuItemFilePath(), 300.0f, 50.0f);
}

void StartMenuRenderer::Render(Screen& screen)
{
    StartMenuScreen& startMenuScreen = (StartMenuScreen&)screen;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    _backgroundRenderer.Render();
    RenderMenu(startMenuScreen);
    _selectedItemAlpha.UpdateBy(0.05f);
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
        glColor4f(v, v, v, _selectedItemAlpha.GetAbsValue());
    }
    else
    {
        glColor4f(v, v, v, 1.0f);
    }
}
