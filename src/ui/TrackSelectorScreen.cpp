#include <ui/TrackSelectorScreen.h>

TrackSelectorScreen::TrackSelectorScreen(
    IScreenNavigator& navigator,
    InputDevices& inputDevices,
    IGameStarter& gameStarter) :
    Screen(ScreenKind::TrackSelector, navigator, inputDevices),
    _gameStarter(gameStarter)
{
}

void TrackSelectorScreen::Activate()
{
}

void TrackSelectorScreen::ProcessInput()
{
    _gameStarter.Start();
    _navigator.NavigateToGame();
}
