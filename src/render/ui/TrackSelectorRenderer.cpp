#include <ui/TrackSelectorScreen.h>
#include <gl/opengl.h>
#include <render/common/RenderConstants.h>
#include <render/ui/TrackSelectorRenderer.h>

TrackSelectorRenderer::TrackSelectorRenderer(
    GraphicItemCollection& graphicItemCollection,
    MenuBackgroundRenderer& backgroundRenderer,
    TrackThumbnailGridRenderer& trackThumbnailGridRenderer) :
    _backgroundRenderer(backgroundRenderer),
    _trackThumbnailGridRenderer(trackThumbnailGridRenderer),
    _selectTrackItem(graphicItemCollection.SelectTrackItem),
    _raceItem(graphicItemCollection.RaceItem),
    _backItem(graphicItemCollection.BackItem)
{
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
    _trackThumbnailGridRenderer.Render(trackSelectorScreen);
    glDisable(GL_BLEND);
    _selectedItemColor.Update();
}

void TrackSelectorRenderer::RenderMenu(TrackSelectorScreen& screen)
{
    glPushMatrix();
    glColor4f(RenderConstants::TextColor, RenderConstants::TextColor, RenderConstants::TextColor, 1.0f);
    glTranslatef(
        (Constants::ScreenWidth - _selectTrackItem.GetWidth()) / 2.0f,
        Constants::ScreenHeight - _selectTrackItem.GetHeight() - 50.0f,
        0.0f);
    _selectTrackItem.Render();
    glPopMatrix();

    _selectedItemColor.SetColorForSelectedItem(TrackSelectorItem::Race == screen.GetSelectedItem());
    glPushMatrix();
    glTranslatef((Constants::ScreenWidth - _raceItem.GetWidth()) / 2.0f, 50.0f, 0.0f);
    _raceItem.Render();
    glPopMatrix();

    _selectedItemColor.SetColorForSelectedItem(TrackSelectorItem::Back == screen.GetSelectedItem());
    glPushMatrix();
    glTranslatef(0.0f, 50.0f, 0.0f);
    _backItem.Render();
    glPopMatrix();
}

TrackSelectorRenderer* TrackSelectorRendererResolvingFactory::Make(Resolver& resolver)
{
    return new TrackSelectorRenderer(
        resolver.Resolve<GraphicItemCollection>(),
        resolver.Resolve<MenuBackgroundRenderer>(),
        resolver.Resolve<TrackThumbnailGridRenderer>());
}
