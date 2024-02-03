#pragma once

#include <ui/Screen.h>
#include <render/ui/MenuItemCollection.h>
#include <render/ui/ScreenRenderer.h>

class TrackSelectorRenderer : public ScreenRenderer
{
public:
    void Init(MenuItemCollection& menuItemCollection) override;
    void Render(Screen& screen) override;
};
