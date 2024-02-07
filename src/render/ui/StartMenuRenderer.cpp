#include <gl/opengl.h>
#include <core/Constants.h>
#include <ui/StartMenuScreen.h>
#include <render/ui/StartMenuRenderer.h>

StartMenuRenderer::StartMenuRenderer(MenuBackgroundRenderer& backgroundRenderer) :
    _backgroundRenderer(backgroundRenderer)
{
    _startGameItem = nullptr;
    _exitItem = nullptr;
}

void StartMenuRenderer::Init(GraphicItemCollection& graphicItemCollection)
{
    _startGameItem = &graphicItemCollection.StartGameItem;
    _exitItem = &graphicItemCollection.ExitItem;
}

void StartMenuRenderer::Render(Screen& screen)
{
    StartMenuScreen& startMenuScreen = (StartMenuScreen&)screen;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    _backgroundRenderer.Render();
    RenderMenu(startMenuScreen);
    _selectedItemColor.Update();
}

void StartMenuRenderer::RenderMenu(StartMenuScreen& screen)
{
    glLoadIdentity();
    gluOrtho2D(0.0, Constants::ScreenWidth, 0.0, Constants::ScreenHeight);
    glEnable(GL_BLEND);

    _selectedItemColor.SetColorForSelectedItem(StartMenuItem::Exit == screen.GetSelectedItem());
    glTranslatef(Constants::ScreenWidth - _exitItem->GetWidth() - 100.0f, 50.0f, 0.0f);
    _exitItem->Render();

    _selectedItemColor.SetColorForSelectedItem(StartMenuItem::StartGame == screen.GetSelectedItem());
    glTranslatef(0.0f, 75.0f, 0.0f);
    _startGameItem->Render();

    glDisable(GL_BLEND);
}
