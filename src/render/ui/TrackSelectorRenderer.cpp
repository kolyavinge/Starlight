#include <gl/opengl.h>
#include <ui/TrackSelectorScreen.h>
#include <render/ui/TrackSelectorRenderer.h>

TrackSelectorRenderer::TrackSelectorRenderer(MenuBackgroundRenderer& backgroundRenderer) :
    _backgroundRenderer(backgroundRenderer),
    _fadeEffect(FadeDirection::ToBlack, 100)
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
    _selectedItemAlpha.UpdateBy(0.05f);
}

void TrackSelectorRenderer::RenderMenu(TrackSelectorScreen& screen)
{
    glLoadIdentity();
    glOrtho(0.0, Constants::ScreenWidth, 0.0, Constants::ScreenHeight, -1.0, 1.0);
    glEnable(GL_BLEND);

    glPushMatrix();
    glColor4f(0.7f, 0.7f, 0.7f, 1.0f);
    glTranslatef((Constants::ScreenWidth - _selectTrackItem->GetWidth()) / 2.0f, Constants::ScreenHeight - _selectTrackItem->GetHeight() - 50.0f, 0.0f);
    _selectTrackItem->Render();
    glPopMatrix();

    SetAlphaForSelectedItem(screen, TrackSelectorItem::Race);
    glPushMatrix();
    glTranslatef((Constants::ScreenWidth - _raceItem->GetWidth()) / 2.0f, 50.0f, 0.0f);
    _raceItem->Render();
    glPopMatrix();

    SetAlphaForSelectedItem(screen, TrackSelectorItem::Back);
    glTranslatef(0.0f, 50.0f, 0.0f);
    _backItem->Render();

    glDisable(GL_BLEND);
}

void TrackSelectorRenderer::SetAlphaForSelectedItem(TrackSelectorScreen& screen, TrackSelectorItem item)
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
