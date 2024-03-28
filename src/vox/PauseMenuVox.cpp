#include <ui/PauseMenuScreen.h>
#include <vox/PauseMenuVox.h>

PauseMenuVox::PauseMenuVox(SampleCollection& sampleCollection) :
    _menuItemVox(PauseMenuItem::Resume)
{
    _menuItemVox.Init(sampleCollection);
}

void PauseMenuVox::Voice(Screen& screen)
{
    PauseMenuScreen& pauseMenuScreen = (PauseMenuScreen&)screen;
    _menuItemVox.Voice(pauseMenuScreen.GetSelectedItem());
}

PauseMenuVox* PauseMenuVoxResolvingFactory::Make(Resolver& resolver)
{
    return new PauseMenuVox(resolver.Resolve<SampleCollection>());
}
