#include <anx/GraphicResources.h>
#include <render/ui/GraphicItemCollection.h>

void GraphicItemCollection::Init()
{
    StartGameItem.Load(GraphicResources::GetStartGameMenuItemFilePath());
    ExitItem.Load(GraphicResources::GetExitMenuItemFilePath());
    SelectTrackItem.Load(GraphicResources::GetSelectTrackMenuItemFilePath());
    RaceItem.Load(GraphicResources::GetRaceMenuItemFilePath());
    BackItem.Load(GraphicResources::GetBackMenuItemFilePath());
    PauseItem.Load(GraphicResources::GetPauseItemFilePath());
    ResumeItem.Load(GraphicResources::GetResumeMenuItemFilePath());
    StartMenuItem.Load(GraphicResources::GetStartMenuMenuItemFilePath());
}
