#include <ui/TrackSelectorScreen.h>

TrackSelectorScreen::TrackSelectorScreen(
    IScreenNavigator& navigator,
    InputDevices& inputDevices,
    TrackManager& trackManager,
    Race& race) :
    Screen(ScreenKind::TrackSelector, navigator, inputDevices),
    _trackManager(trackManager),
    _race(race)
{
}

void TrackSelectorScreen::Activate()
{
}

void TrackSelectorScreen::ProcessInput()
{
    _race.Start(_trackManager.GetCurrentTrack());
    _navigator.NavigateToRace();
}
