#include <ui/StartMenuScreen.h>
#include <vox/StartMenuVox.h>

void StartMenuVox::Init(SampleCollection& sampleCollection)
{
    _menuItemVox.Init(sampleCollection);
}

void StartMenuVox::Voice(Screen& screen)
{
    StartMenuScreen& startMenuScreen = (StartMenuScreen&)screen;
    _menuItemVox.Voice(startMenuScreen.GetSelectedItem());
}
