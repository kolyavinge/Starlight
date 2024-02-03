#include <anx/GraphicResources.h>
#include <render/ui/MenuItemCollection.h>

void MenuItemCollection::Init()
{
    StartGameItem.Load(GraphicResources::GetStartGameMenuItemFilePath(), 300.0f, 50.0f);
    ExitItem.Load(GraphicResources::GetExitMenuItemFilePath(), 300.0f, 50.0f);
    PauseItem.Load(GraphicResources::GetPauseItemFilePath(), 300.0f, 50.0f);
    ResumeItem.Load(GraphicResources::GetResumeMenuItemFilePath(), 300.0f, 50.0f);
    StartMenuItem.Load(GraphicResources::GetStartMenuMenuItemFilePath(), 300.0f, 50.0f);
}
