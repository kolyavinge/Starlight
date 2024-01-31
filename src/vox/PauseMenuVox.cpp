#include <ui/PauseMenuScreen.h>
#include <vox/PauseMenuVox.h>

void PauseMenuVox::Init(SampleCollection& sampleCollection)
{
    _menuItemVox.Init(sampleCollection);
}

void PauseMenuVox::Voice(Screen& screen)
{
    PauseMenuScreen& pauseMenuScreen = (PauseMenuScreen&)screen;
    _menuItemVox.Voice(pauseMenuScreen.GetSelectedItem());
}
