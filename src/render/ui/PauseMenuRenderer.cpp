#include <gl/opengl.h>
#include <core/Resources.h>
#include <ui/PauseMenuScreen.h>
#include <render/ui/PauseMenuRenderer.h>

PauseMenuRenderer::PauseMenuRenderer(RaceRenderer& raceRenderer) :
    _raceRenderer(raceRenderer)
{
}

void PauseMenuRenderer::Init()
{
    _pauseItem.Load(Resources::GetPauseItemFilePath(), 300.0f, 50.0f);
    _resumeItem.Load(Resources::GetResumeMenuItemFilePath(), 300.0f, 50.0f);
    _startMenuItem.Load(Resources::GetStartMenuMenuItemFilePath(), 300.0f, 50.0f);
}

void PauseMenuRenderer::Render(Screen& screen)
{
    PauseMenuScreen& pauseMenuScreen = (PauseMenuScreen&)screen;
    _raceRenderer.Render(pauseMenuScreen.Race);
    glLoadIdentity();
    glOrtho(0.0, Constants::ScreenWidth, 0.0, Constants::ScreenHeight, -1.0, 1.0);
    glEnable(GL_BLEND);
    RenderDarkBackground();
    RenderMenu(pauseMenuScreen);
    glDisable(GL_BLEND);
    _selectedItemAlpha.UpdateBy(0.05f);
}

void PauseMenuRenderer::RenderMenu(PauseMenuScreen& screen)
{
    glColor4f(0.9f, 0.9f, 0.9f, 1.0f);
    glTranslatef(
        (Constants::ScreenWidth - _pauseItem.GetWidth()) / 2.0f,
        (Constants::ScreenHeight - _pauseItem.GetHeight()) / 2.0f + 200.0f,
        0.0f);
    _pauseItem.Render();

    SetAlphaForSelectedItem(screen, PauseMenuItem::Resume);
    glTranslatef(0.0f, -200.0f, 0.0f);
    _resumeItem.Render();

    SetAlphaForSelectedItem(screen, PauseMenuItem::StartMenu);
    glTranslatef(0.0f, -75.0f, 0.0f);
    _startMenuItem.Render();
}

void PauseMenuRenderer::RenderDarkBackground()
{
    glColor4f(0.0f, 0.0f, 0.0f, 0.5f);
    glBegin(GL_QUADS);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(Constants::ScreenWidth, 0.0f, 0.0f);
    glVertex3f(Constants::ScreenWidth, Constants::ScreenHeight, 0.0f);
    glVertex3f(0.0f, Constants::ScreenHeight, 0.0f);
    glEnd();
}

void PauseMenuRenderer::SetAlphaForSelectedItem(PauseMenuScreen& screen, PauseMenuItem item)
{
    const float v = 0.9f;
    if (item == screen.GetSelectedItem())
    {
        glColor4f(v, v, v, _selectedItemAlpha.GetAbsValue());
    }
    else
    {
        glColor4f(v, v, v, 1.0f);
    }
}
