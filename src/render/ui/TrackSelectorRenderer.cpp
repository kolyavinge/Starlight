#include <gl/opengl.h>
#include <ui/TrackSelectorScreen.h>
#include <render/common/RenderConstants.h>
#include <render/ui/TrackSelectorRenderer.h>

TrackSelectorRenderer::TrackSelectorRenderer(MenuBackgroundRenderer& backgroundRenderer) :
    _backgroundRenderer(backgroundRenderer)
{
    _selectTrackItem = nullptr;
    _raceItem = nullptr;
    _backItem = nullptr;
}

void TrackSelectorRenderer::Init(GraphicItemCollection& graphicItemCollection)
{
    _selectTrackItem = &graphicItemCollection.SelectTrackItem;
    _raceItem = &graphicItemCollection.RaceItem;
    _backItem = &graphicItemCollection.BackItem;
}

void TrackSelectorRenderer::Render(Screen& screen)
{
    TrackSelectorScreen& trackSelectorScreen = (TrackSelectorScreen&)screen;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    _backgroundRenderer.Render();
    glLoadIdentity();
    glOrtho(0.0, Constants::ScreenWidth, 0.0, Constants::ScreenHeight, -1000.0, 1000.0);
    glEnable(GL_BLEND);
    RenderMenu(trackSelectorScreen);
    glDisable(GL_BLEND);
    _selectedItemColor.Update();
}

void TrackSelectorRenderer::RenderMenu(TrackSelectorScreen& screen)
{
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
}
