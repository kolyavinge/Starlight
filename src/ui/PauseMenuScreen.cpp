#include <windows.h>
#include <lib/Array.h>
#include <ui/PauseMenuScreen.h>

PauseMenuScreen::PauseMenuScreen(
    IScreenNavigator& navigator,
    InputDevices& inputDevices,
    IPauseSwitcher& pauseSwitcher) :
    Screen(ScreenKind::PauseMenu, navigator, inputDevices),
    _pauseSwitcher(pauseSwitcher)
{
    Array<PauseMenuItem, 2> items;
    items[0] = PauseMenuItem::Resume;
    items[1] = PauseMenuItem::StartMenu;
    _selector.Init(items);
}

PauseMenuItem PauseMenuScreen::GetSelectedItem()
{
    return _selector.GetSelectedItem();
}

void PauseMenuScreen::ProcessInput()
{
    bool hasSelection = _selector.ProcessSelection(_inputDevices);
    if (hasSelection) return;

    if (_inputDevices.Keyboard.IsPressed(VK_ESCAPE))
    {
        _pauseSwitcher.SwitchPause();
        _navigator.NavigateToGame();
    }
    else if (
        _inputDevices.Keyboard.IsPressed(VK_RETURN) ||
        _inputDevices.Keyboard.IsPressed(VK_SPACE) ||
        _inputDevices.Joystick.IsButton1Pressed())
    {
        if (GetSelectedItem() == PauseMenuItem::Resume)
        {
            _pauseSwitcher.SwitchPause();
            _navigator.NavigateToGame();
        }
        else if (GetSelectedItem() == PauseMenuItem::StartMenu)
        {
            _navigator.NavigateToStartMenu();
        }
    }
}
