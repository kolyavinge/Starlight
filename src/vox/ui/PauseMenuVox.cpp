#include <ui/PauseMenuScreen.h>
#include <vox/ui/PauseMenuVox.h>

PauseMenuVox::PauseMenuVox(AudioDataCollection& audioDataCollection) :
    _menuItemVox(PauseMenuItem::Resume, audioDataCollection)
{
}

void PauseMenuVox::Voice(Screen& screen)
{
    PauseMenuScreen& pauseMenuScreen = (PauseMenuScreen&)screen;
    _menuItemVox.Voice(pauseMenuScreen.GetSelectedItem());
}

PauseMenuVox* PauseMenuVoxResolvingFactory::Make(Resolver& resolver)
{
    return new PauseMenuVox(resolver.Resolve<AudioDataCollection>());
}
