#include <ui/StartMenuScreen.h>
#include <vox/StartMenuVox.h>

StartMenuVox::StartMenuVox(AudioDataCollection& audioDataCollection) :
    _menuItemVox(StartMenuItem::StartGame, audioDataCollection)
{
}

void StartMenuVox::Voice(Screen& screen)
{
    StartMenuScreen& startMenuScreen = (StartMenuScreen&)screen;
    _menuItemVox.Voice(startMenuScreen.GetSelectedItem());
}

StartMenuVox* StartMenuVoxResolvingFactory::Make(Resolver& resolver)
{
    return new StartMenuVox(resolver.Resolve<AudioDataCollection>());
}
