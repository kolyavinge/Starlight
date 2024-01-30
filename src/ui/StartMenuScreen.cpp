#include <windows.h>
#include <lib/Array.h>
#include <ui/StartMenuScreen.h>
#include <win/App.h>

StartMenuScreen::StartMenuScreen(
    IScreenNavigator& navigator,
    InputDevices& inputDevices) :
    Screen(ScreenKind::StartMenu, navigator, inputDevices)
{
    Array<StartMenuItem, 2> items;
    items[0] = StartMenuItem::StartGame;
    items[1] = StartMenuItem::Exit;
    _selector.Init(items);
}

StartMenuItem StartMenuScreen::GetSelectedItem()
{
    return _selector.GetSelectedItem();
}

void StartMenuScreen::ProcessInput()
{
    bool hasSelection = _selector.ProcessSelection(_inputDevices);
    if (hasSelection) return;
    if (_inputDevices.Keyboard.IsPressed(VK_RETURN) ||
        _inputDevices.Keyboard.IsPressed(VK_SPACE) ||
        _inputDevices.Joystick.IsButton1Pressed())
    {
        _inputDevices.Keyboard.Release(VK_RETURN);
        _inputDevices.Keyboard.Release(VK_SPACE);
        if (GetSelectedItem() == StartMenuItem::StartGame)
        {
            _navigator.NavigateToTrackSelector();
        }
        else if (GetSelectedItem() == StartMenuItem::Exit)
        {
            App::Shutdown();
        }
    }
}
