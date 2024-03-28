#include <ui/StartMenuScreen.h>
#include <vox/StartMenuVox.h>

StartMenuVox::StartMenuVox(SampleCollection& sampleCollection) :
    _menuItemVox(StartMenuItem::StartGame)
{
    _menuItemVox.Init(sampleCollection);
}

void StartMenuVox::Voice(Screen& screen)
{
    StartMenuScreen& startMenuScreen = (StartMenuScreen&)screen;
    _menuItemVox.Voice(startMenuScreen.GetSelectedItem());
}

StartMenuVox* StartMenuVoxResolvingFactory::Make(Resolver& resolver)
{
    return new StartMenuVox(resolver.Resolve<SampleCollection>());
}
