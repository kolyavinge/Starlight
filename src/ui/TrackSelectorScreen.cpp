#include <ui/TrackSelectorScreen.h>

TrackSelectorScreen::TrackSelectorScreen(
    IScreenNavigator& navigator,
    InputDevices& inputDevices) :
    Screen(ScreenKind::TrackSelector, navigator, inputDevices)
{
}

void TrackSelectorScreen::ProcessInput()
{
    _navigator.NavigateToGame();
}
