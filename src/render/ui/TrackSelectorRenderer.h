#pragma once

#include <calc/SinPeriodValue.h>
#include <ui/Screen.h>
#include <ui/TrackSelectorScreen.h>
#include <gl/TexturedRect.h>
#include <render/effect/Fade.h>
#include <render/common/MenuBackgroundRenderer.h>
#include <render/ui/MenuItemCollection.h>
#include <render/ui/ScreenRenderer.h>

class TrackSelectorRenderer : public ScreenRenderer
{
    MenuBackgroundRenderer& _backgroundRenderer;
    TexturedRect* _selectTrackItem;
    TexturedRect* _raceItem;
    TexturedRect* _backItem;
    Fade _fadeEffect;
    SinPeriodValue _selectedItemAlpha;

public:
    TrackSelectorRenderer(MenuBackgroundRenderer& backgroundRenderer);

    void Init(MenuItemCollection& menuItemCollection) override;
    void Render(Screen& screen) override;

private:
    void RenderMenu(TrackSelectorScreen& screen);
    void SetAlphaForSelectedItem(TrackSelectorScreen& screen, TrackSelectorItem item);
};
