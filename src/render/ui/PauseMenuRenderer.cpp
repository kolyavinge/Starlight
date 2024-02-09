#include <gl/opengl.h>
#include <ui/PauseMenuScreen.h>
#include <render/common/RenderConstants.h>
#include <render/ui/PauseMenuRenderer.h>

PauseMenuRenderer::PauseMenuRenderer(RaceRenderer& raceRenderer) :
    _raceRenderer(raceRenderer)
{
    _pauseItem = nullptr;
    _resumeItem = nullptr;
    _startMenuItem = nullptr;
}

void PauseMenuRenderer::Init(GraphicItemCollection& graphicItemCollection)
{
    _pauseItem = &graphicItemCollection.PauseItem;
    _resumeItem = &graphicItemCollection.ResumeItem;
    _startMenuItem = &graphicItemCollection.StartMenuItem;
}

void PauseMenuRenderer::Render(Screen& screen)
{
    PauseMenuScreen& pauseMenuScreen = (PauseMenuScreen&)screen;
    _raceRenderer.Render(pauseMenuScreen.Race);
    glLoadIdentity();
    gluOrtho2D(0.0, Constants::ScreenWidth, 0.0, Constants::ScreenHeight);
    glEnable(GL_BLEND);
    RenderDarkBackground();
    RenderMenu(pauseMenuScreen);
    glDisable(GL_BLEND);
    _selectedItemColor.Update();
}

void PauseMenuRenderer::RenderMenu(PauseMenuScreen& screen)
{
    glColor4f(RenderConstants::TextColor, RenderConstants::TextColor, RenderConstants::TextColor, 1.0f);
    glTranslatef(
        (Constants::ScreenWidth - _pauseItem->GetWidth()) / 2.0f,
        (Constants::ScreenHeight - _pauseItem->GetHeight()) / 2.0f + 200.0f,
        0.0f);
    _pauseItem->Render();

    _selectedItemColor.SetColorForSelectedItem(PauseMenuItem::Resume == screen.GetSelectedItem());
    glTranslatef(0.0f, -200.0f, 0.0f);
    _resumeItem->Render();

    _selectedItemColor.SetColorForSelectedItem(PauseMenuItem::StartMenu == screen.GetSelectedItem());
    glTranslatef(0.0f, -75.0f, 0.0f);
    _startMenuItem->Render();
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
