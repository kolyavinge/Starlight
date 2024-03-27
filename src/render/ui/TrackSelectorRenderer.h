#pragma once

#include <lib/di/ResolvingFactory.h>
#include <ui/Screen.h>
#include <ui/TrackSelectorScreen.h>
#include <gl/TexturedRect.h>
#include <render/common/GraphicItemCollection.h>
#include <render/common/MenuBackgroundRenderer.h>
#include <render/common/TrackThumbnailGridRenderer.h>
#include <render/ui/SelectedItemColor.h>
#include <render/ui/ScreenRenderer.h>

class TrackSelectorRenderer : public ScreenRenderer
{
    MenuBackgroundRenderer& _backgroundRenderer;
    TrackThumbnailGridRenderer& _trackThumbnailGridRenderer;
    TexturedRect& _selectTrackItem;
    TexturedRect& _raceItem;
    TexturedRect& _backItem;
    SelectedItemColor _selectedItemColor;

public:
    TrackSelectorRenderer(
        GraphicItemCollection& graphicItemCollection,
        MenuBackgroundRenderer& backgroundRenderer,
        TrackThumbnailGridRenderer& trackThumbnailGridRenderer);

    void Render(Screen& screen) override;

private:
    void RenderMenu(TrackSelectorScreen& screen);
};

class TrackSelectorRendererResolvingFactory : public ResolvingFactory<TrackSelectorRenderer>
{
public:
    TrackSelectorRenderer* Make(Resolver& resolver) override;
};
