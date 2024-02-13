#include <lib/Exceptions.h>
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

    Array<TrackSelectorItem, 4> tracks;
    tracks[0] = TrackSelectorItem::Track1;
    tracks[1] = TrackSelectorItem::Track2;
    tracks[2] = TrackSelectorItem::Track3;
    tracks[3] = TrackSelectorItem::Track4;
    _trackSelector.Init(tracks);

    _activeSelector = &_itemSelector;
}

TrackSelectorItem TrackSelectorScreen::GetSelectedItem()
{
    return _activeSelector->GetSelectedItem();
}

void TrackSelectorScreen::Activate(Screen*)
{
    _itemSelector.Reset();
    _trackSelector.Reset();
}

void TrackSelectorScreen::ProcessInput()
{
    bool hasSelection = _activeSelector->ProcessSelection(_inputDevices);
    if (hasSelection) return;

    if (IsMenuActive())
    {
        if (_inputDevices.Keyboard.IsPressed(VK_UP) ||
            _inputDevices.Joystick.IsUpPressed())
        {
            _trackSelector.Reset();
            _activeSelector = &_trackSelector;
        }
        else if (
            _inputDevices.Keyboard.IsPressed(VK_RETURN) ||
            _inputDevices.Keyboard.IsPressed(VK_SPACE) ||
            _inputDevices.Joystick.IsButton1Pressed())
        {
            if (GetSelectedItem() == TrackSelectorItem::Back)
            {
                _navigator.NavigateTo(ScreenKind::StartMenu);
            }
            else if (GetSelectedItem() == TrackSelectorItem::Race)
            {
                _race.Init(GetSelectedTrack());
                _navigator.NavigateTo(ScreenKind::RacePreparation);
            }
        }
    }
    else
    {
        if (_inputDevices.Keyboard.IsPressed(VK_RETURN) ||
            _inputDevices.Keyboard.IsPressed(VK_SPACE) ||
            _inputDevices.Joystick.IsButton1Pressed())
        {
            _itemSelector.Reset();
            _activeSelector = &_itemSelector;
        }
    }
}

Track& TrackSelectorScreen::GetSelectedTrack()
{
    if (_trackSelector.GetSelectedItem() == TrackSelectorItem::Track1)
    {
        return _trackManager.Track1;
    }
    else if (_trackSelector.GetSelectedItem() == TrackSelectorItem::Track2)
    {
        return _trackManager.Track2;
    }
    else if (_trackSelector.GetSelectedItem() == TrackSelectorItem::Track3)
    {
        return _trackManager.Track3;
    }
    else if (_trackSelector.GetSelectedItem() == TrackSelectorItem::Track4)
    {
        return _trackManager.Track4;
    }
    else
    {
        throw ArgumentException();
    }
}

bool TrackSelectorScreen::IsMenuActive()
{
    return dynamic_cast<LinearMenuItemSelector<TrackSelectorItem, 2>*>(_activeSelector);
}
