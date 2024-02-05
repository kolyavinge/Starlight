#include <gl/opengl.h>
#include <ui/TrackSelectorScreen.h>
#include <render/ui/RenderConstants.h>
#include <render/ui/TrackSelectorRenderer.h>

TrackSelectorRenderer::TrackSelectorRenderer(MenuBackgroundRenderer& backgroundRenderer) :
    _backgroundRenderer(backgroundRenderer)
{
    _selectTrackItem = nullptr;
    _raceItem = nullptr;
    _backItem = nullptr;
}

void TrackSelectorRenderer::Init(MenuItemCollection& menuItemCollection)
{
    _selectTrackItem = &menuItemCollection.SelectTrackItem;
    _raceItem = &menuItemCollection.RaceItem;
    _backItem = &menuItemCollection.BackItem;
}

void TrackSelectorRenderer::Render(Screen& screen)
{
    TrackSelectorScreen& trackSelectorScreen = (TrackSelectorScreen&)screen;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    _backgroundRenderer.Render();
    RenderMenu(trackSelectorScreen);
    _selectedItemColor.Update();
}

void TrackSelectorRenderer::RenderMenu(TrackSelectorScreen& screen)
{
    glLoadIdentity();
    gluOrtho2D(0.0, Constants::ScreenWidth, 0.0, Constants::ScreenHeight);
    glEnable(GL_BLEND);

    glPushMatrix();
    glColor4f(RenderConstants::TextColor, RenderConstants::TextColor, RenderConstants::TextColor, 1.0f);
    glTranslatef(
        (Constants::ScreenWidth - _selectTrackItem->GetWidth()) / 2.0f,
        Constants::ScreenHeight - _selectTrackItem->GetHeight() - 50.0f,
        0.0f);
    _selectTrackItem->Render();
    glPopMatrix();

    _selectedItemColor.SetColorForSelectedItem(TrackSelectorItem::Race == screen.GetSelectedItem());
    glPushMatrix();
    glTranslatef((Constants::ScreenWidth - _raceItem->GetWidth()) / 2.0f, 50.0f, 0.0f);
    _raceItem->Render();
    glPopMatrix();

    _selectedItemColor.SetColorForSelectedItem(TrackSelectorItem::Back == screen.GetSelectedItem());
    glTranslatef(0.0f, 50.0f, 0.0f);
    _backItem->Render();

    glDisable(GL_BLEND);
}
