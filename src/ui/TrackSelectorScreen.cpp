#include <lib/Exceptions.h>
#include <lib/Object.h>
#include <input/Keys.h>
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
    _itemSelector.AddItem(TrackSelectorItem::Race);
    _itemSelector.AddItem(TrackSelectorItem::Back);

    _trackSelector.SetItem(0, 0, TrackSelectorItem::Track1);
    _trackSelector.SetItem(0, 1, TrackSelectorItem::Track2);
    _trackSelector.SetItem(1, 0, TrackSelectorItem::Track3);
    _trackSelector.SetItem(1, 1, TrackSelectorItem::Track4);

    _activeSelector = nullptr;
}

TrackSelectorItem TrackSelectorScreen::GetSelectedItem()
{
    return _activeSelector->GetSelectedItem();
}

void TrackSelectorScreen::Activate(Screen*)
{
    _itemSelector.Reset();
    _trackSelector.Reset();
    _activeSelector = &_trackSelector;
}

void TrackSelectorScreen::ProcessInput()
{
    bool hasSelection = _activeSelector->ProcessSelection(_inputDevices);
    if (hasSelection) return;

    if (IsMenuSelectionActive())
    {
        if (_inputDevices.Keyboard.IsPressed(Keys::Up) ||
            _inputDevices.Keyboard.IsPressed('W') ||
            _inputDevices.Joystick.IsUpPressed())
        {
            _trackSelector.Reset();
            _activeSelector = &_trackSelector;
        }
        else if (
            _inputDevices.Keyboard.IsPressed(Keys::Return) ||
            _inputDevices.Keyboard.IsPressed(Keys::Space) ||
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
        if (_inputDevices.Keyboard.IsPressed(Keys::Return) ||
            _inputDevices.Keyboard.IsPressed(Keys::Space) ||
            _inputDevices.Joystick.IsButton1Pressed())
        {
            _itemSelector.Reset();
            _activeSelector = &_itemSelector;
        }
    }
}

Track& TrackSelectorScreen::GetSelectedTrack()
{
    return GetTrackByItem(_trackSelector.GetSelectedItem());
}

int TrackSelectorScreen::GetTrackGridRowsCount()
{
    return _trackSelector.GetRowsCount();
}

int TrackSelectorScreen::GetTrackGridColsCount()
{
    return _trackSelector.GetColsCount();
}

Track& TrackSelectorScreen::GetTrackByCell(int row, int col)
{
    return GetTrackByItem(_trackSelector.GetItemByCell(row, col));
}

bool TrackSelectorScreen::IsMenuSelectionActive()
{
    return Object::ReferenceEquals(*_activeSelector, _itemSelector);
}

bool TrackSelectorScreen::IsTrackSelectionActive()
{
    return Object::ReferenceEquals(*_activeSelector, _trackSelector);
}

Track& TrackSelectorScreen::GetTrackByItem(TrackSelectorItem item)
{
    if (item == TrackSelectorItem::Track1) return _trackManager.Track1;
    if (item == TrackSelectorItem::Track2) return _trackManager.Track2;
    if (item == TrackSelectorItem::Track3) return _trackManager.Track3;
    if (item == TrackSelectorItem::Track4) return _trackManager.Track4;

    throw ArgumentException();
}

TrackSelectorScreen* TrackSelectorScreenResolvingFactory::Make(Resolver& resolver)
{
    return new TrackSelectorScreen(
        resolver.Resolve<IScreenNavigator>(),
        resolver.Resolve<InputDevices>(),
        resolver.Resolve<TrackManager>(),
        resolver.Resolve<Race>());
}
