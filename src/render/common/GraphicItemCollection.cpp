#include <anx/GraphicResources.h>
#include <render/common/GraphicItemCollection.h>

GraphicItemCollection::GraphicItemCollection()
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
    Position1Item.Load(GraphicResources::GetPosition1ItemFilePath());
    Position2Item.Load(GraphicResources::GetPosition2ItemFilePath());
    Position3Item.Load(GraphicResources::GetPosition3ItemFilePath());
    Position4Item.Load(GraphicResources::GetPosition4ItemFilePath());
    ExplosionTexture.Load(GraphicResources::GetExplosionFilePath(), 17);
    PowerUpHealthTexture.Load(GraphicResources::GetPowerUpHealthFilePath());
    PowerUpMachinegunTexture.Load(GraphicResources::GetPowerUpMachinegunFilePath());
    PowerUpNitroTexture.Load(GraphicResources::GetPowerUpNitroFilePath());
}

GraphicItemCollection* GraphicItemCollectionResolvingFactory::Make(Resolver&)
{
    return new GraphicItemCollection();
}
