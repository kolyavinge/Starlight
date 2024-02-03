#include <ui/PauseMenuScreen.h>
#include <vox/PauseMenuVox.h>

PauseMenuVox::PauseMenuVox() :
    _menuItemVox(PauseMenuItem::Resume)
{
}

void PauseMenuVox::Init(SampleCollection& sampleCollection)
{
    _menuItemVox.Init(sampleCollection);
}

void PauseMenuVox::Voice(Screen& screen)
{
    PauseMenuScreen& pauseMenuScreen = (PauseMenuScreen&)screen;
    _menuItemVox.Voice(pauseMenuScreen.GetSelectedItem());
}
