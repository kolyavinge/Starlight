#pragma once

#include <lib/di/ResolvingFactory.h>
#include <ui/Screen.h>
#include <ui/StartMenuScreen.h>
#include <gl/TexturedRect.h>
#include <render/common/MenuBackgroundRenderer.h>
#include <render/ui/SelectedItemColor.h>
#include <render/ui/GraphicItemCollection.h>
#include <render/ui/ScreenRenderer.h>

class StartMenuRenderer : public ScreenRenderer
{
    MenuBackgroundRenderer& _backgroundRenderer;
    TexturedRect* _startGameItem;
    TexturedRect* _exitItem;
    SelectedItemColor _selectedItemColor;

public:
    StartMenuRenderer(MenuBackgroundRenderer& backgroundRenderer);

    void Init(GraphicItemCollection& graphicItemCollection) override;
    void Render(Screen& screen) override;

private:
    void RenderMenu(StartMenuScreen& screen);
};

class StartMenuRendererResolvingFactory : public ResolvingFactory<StartMenuRenderer>
{
public:
    StartMenuRenderer* Make(Resolver& resolver) override;
};
