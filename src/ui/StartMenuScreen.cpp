#include <input/Keys.h>
#include <ui/StartMenuScreen.h>
#include <win/App.h>

StartMenuScreen::StartMenuScreen(
    IScreenNavigator& navigator,
    InputDevices& inputDevices) :
    Screen(ScreenKind::StartMenu, navigator, inputDevices),
    _selector(LinearMenuItemSelectorOrientation::Vertical)
{
    _selector.AddItem(StartMenuItem::StartGame);
    _selector.AddItem(StartMenuItem::Exit);
}

StartMenuItem StartMenuScreen::GetSelectedItem()
{
    return _selector.GetSelectedItem();
}

void StartMenuScreen::Activate(Screen*)
{
    _selector.Reset();
}

void StartMenuScreen::ProcessInput()
{
    bool hasSelection = _selector.ProcessSelection(_inputDevices);
    if (hasSelection) return;
    if (_inputDevices.Keyboard.IsPressed(Keys::Return) ||
        _inputDevices.Keyboard.IsPressed(Keys::Space) ||
        _inputDevices.Joystick.IsButton1Pressed())
    {
        if (GetSelectedItem() == StartMenuItem::StartGame)
        {
            _navigator.NavigateTo(ScreenKind::TrackSelector);
        }
        else if (GetSelectedItem() == StartMenuItem::Exit)
        {
            App::Shutdown();
        }
    }
}

StartMenuScreen* StartMenuScreenResolvingFactory::Make(Resolver& resolver)
{
    return new StartMenuScreen(
        resolver.Resolve<IScreenNavigator>(),
        resolver.Resolve<InputDevices>());
}
