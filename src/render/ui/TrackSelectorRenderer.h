#pragma once

#include <ui/Screen.h>
#include <ui/TrackSelectorScreen.h>
#include <gl/TexturedRect.h>
#include <render/common/MenuBackgroundRenderer.h>
#include <render/ui/SelectedItemColor.h>
#include <render/ui/MenuItemCollection.h>
#include <render/ui/ScreenRenderer.h>

class TrackSelectorRenderer : public ScreenRenderer
{
    MenuBackgroundRenderer& _backgroundRenderer;
    TexturedRect* _selectTrackItem;
    TexturedRect* _raceItem;
    TexturedRect* _backItem;
    SelectedItemColor _selectedItemColor;

public:
    TrackSelectorRenderer(MenuBackgroundRenderer& backgroundRenderer);

    void Init(MenuItemCollection& menuItemCollection) override;
    void Render(Screen& screen) override;

private:
    void RenderMenu(TrackSelectorScreen& screen);
};
