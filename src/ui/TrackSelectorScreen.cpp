#include <ui/TrackSelectorScreen.h>

TrackSelectorScreen::TrackSelectorScreen(
    IScreenNavigator& navigator,
    InputDevices& inputDevices,
    TrackManager& trackManager,
    Race& race) :
    Screen(ScreenKind::TrackSelector, navigator, inputDevices),
    _selector(MenuItemSelectorOrientation::Horizontal),
    _trackManager(trackManager),
    _race(race)
{
    Array<TrackSelectorItem, 2> items;
    items[0] = TrackSelectorItem::Race;
    items[1] = TrackSelectorItem::Back;
    _selector.Init(items);
}

TrackSelectorItem TrackSelectorScreen::GetSelectedItem()
{
    return _selector.GetSelectedItem();
}

void TrackSelectorScreen::Activate(Screen*)
{
    _selector.Reset();
}

void TrackSelectorScreen::ProcessInput()
{
    bool hasSelection = _selector.ProcessSelection(_inputDevices);
    if (hasSelection) return;

    if (_inputDevices.Keyboard.IsPressed(VK_RETURN) ||
        _inputDevices.Keyboard.IsPressed(VK_SPACE) ||
        _inputDevices.Joystick.IsButton1Pressed())
    {
        if (GetSelectedItem() == TrackSelectorItem::Back)
        {
            _navigator.NavigateTo(ScreenKind::StartMenu);
        }
        else if (GetSelectedItem() == TrackSelectorItem::Race)
        {
            _race.Init(_trackManager.GetCurrentTrack());
            _navigator.NavigateTo(ScreenKind::RacePreparation);
        }
    }
}
