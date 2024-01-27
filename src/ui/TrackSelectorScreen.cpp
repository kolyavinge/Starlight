#include <ui/TrackSelectorScreen.h>

TrackSelectorScreen::TrackSelectorScreen(
    IScreenNavigator& navigator,
    InputDevices& inputDevices) :
    Screen(ScreenKind::TrackSelectorKind, navigator, inputDevices)
{
}

void TrackSelectorScreen::ProcessInput()
{
}
