#include <ui/PauseMenuScreen.h>

PauseMenuScreen::PauseMenuScreen(
    IScreenNavigator& navigator,
    InputDevices& inputDevices) :
    Screen(ScreenKind::PauseMenu, navigator, inputDevices)
{
}

void PauseMenuScreen::ProcessInput()
{
}
