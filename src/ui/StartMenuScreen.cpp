#include <win/App.h>
#include <ui/StartMenuScreen.h>

StartMenuScreen::StartMenuScreen(
    IScreenNavigator& navigator,
    InputDevices& inputDevices) :
    Screen(ScreenKind::StartMenu, navigator, inputDevices)
{
}

void StartMenuScreen::ProcessInput()
{
}
