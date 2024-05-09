#include <input/Keys.h>
#include <ui/PauseMenuScreen.h>

PauseMenuScreen::PauseMenuScreen(
    IScreenNavigator& navigator,
    InputDevices& inputDevices,
    Race& race) :
    Screen(ScreenKind::PauseMenu, navigator, inputDevices),
    _selector(LinearMenuItemSelectorOrientation::Vertical),
    _race(race)
{
    _selector.AddItem(PauseMenuItem::Resume);
    _selector.AddItem(PauseMenuItem::StartMenu);
}

PauseMenuItem PauseMenuScreen::GetSelectedItem()
{
    return _selector.GetSelectedItem();
}

void PauseMenuScreen::Activate(Screen*)
{
    _selector.Reset();
}

void PauseMenuScreen::ProcessInput()
{
    bool hasSelection = _selector.ProcessSelection(_inputDevices);
    if (hasSelection) return;

    if (_inputDevices.Keyboard.IsPressed(Keys::Escape))
    {
        _race.Resume();
        _navigator.NavigateTo(ScreenKind::Race);
    }
    else if (
        _inputDevices.Keyboard.IsPressed(Keys::Return) ||
        _inputDevices.Keyboard.IsPressed(Keys::Space) ||
        _inputDevices.Joystick.IsButton1Pressed())
    {
        if (GetSelectedItem() == PauseMenuItem::Resume)
        {
            _race.Resume();
            _navigator.NavigateTo(ScreenKind::Race);
        }
        else if (GetSelectedItem() == PauseMenuItem::StartMenu)
        {
            _navigator.NavigateTo(ScreenKind::StartMenu);
        }
    }
}

PauseMenuScreen* PauseMenuScreenResolvingFactory::Make(Resolver& resolver)
{
    return new PauseMenuScreen(
        resolver.Resolve<IScreenNavigator>(),
        resolver.Resolve<InputDevices>(),
        resolver.Resolve<Race>());
}
