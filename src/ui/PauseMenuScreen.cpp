#include <ui/PauseMenuScreen.h>

PauseMenuScreen::PauseMenuScreen(
    IScreenNavigator& navigator,
    InputDevices& inputDevices) :
    Screen(ScreenKind::PauseMenuKind, navigator, inputDevices)
{
}

void PauseMenuScreen::ProcessInput()
{
}
