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
    Countdown1Item.Load(GraphicResources::GetCountdown1ItemFilePath());
    Countdown2Item.Load(GraphicResources::GetCountdown2ItemFilePath());
    Countdown3Item.Load(GraphicResources::GetCountdown3ItemFilePath());
    GoItem.Load(GraphicResources::GetGoItemFilePath());
}
