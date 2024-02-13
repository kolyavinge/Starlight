#include <ui/TrackSelectorScreen.h>

TrackSelectorScreen::TrackSelectorScreen(
    IScreenNavigator& navigator,
    InputDevices& inputDevices,
    TrackManager& trackManager,
    Race& race) :
    Screen(ScreenKind::TrackSelector, navigator, inputDevices),
    _itemSelector(LinearMenuItemSelectorOrientation::Horizontal),
    _trackManager(trackManager),
    _race(race)
{
    Array<TrackSelectorItem, 2> items;
    items[0] = TrackSelectorItem::Race;
    items[1] = TrackSelectorItem::Back;
    _itemSelector.Init(items);
    _activeSelector = &_itemSelector;
}

TrackSelectorItem TrackSelectorScreen::GetSelectedItem()
{
    return _activeSelector->GetSelectedItem();
}

void TrackSelectorScreen::Activate(Screen*)
{
    _itemSelector.Reset();
}

void TrackSelectorScreen::ProcessInput()
{
    bool hasSelection = _itemSelector.ProcessSelection(_inputDevices);
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
