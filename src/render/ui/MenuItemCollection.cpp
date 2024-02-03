#include <core/Resources.h>
#include <render/ui/MenuItemCollection.h>

void MenuItemCollection::Init()
{
    StartGameItem.Load(Resources::GetStartGameMenuItemFilePath(), 300.0f, 50.0f);
    ExitItem.Load(Resources::GetExitMenuItemFilePath(), 300.0f, 50.0f);
    PauseItem.Load(Resources::GetPauseItemFilePath(), 300.0f, 50.0f);
    ResumeItem.Load(Resources::GetResumeMenuItemFilePath(), 300.0f, 50.0f);
    StartMenuItem.Load(Resources::GetStartMenuMenuItemFilePath(), 300.0f, 50.0f);
}
