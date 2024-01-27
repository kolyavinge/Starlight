#include <win/App.h>
#include <ui/StartMenuScreen.h>

StartMenuScreen::StartMenuScreen(
    IScreenNavigator& navigator,
    InputDevices& inputDevices) :
    Screen(ScreenKind::StartMenuKind, navigator, inputDevices)
{
}

void StartMenuScreen::ProcessInput()
{
}
