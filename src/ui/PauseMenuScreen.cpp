#include <windows.h>
#include <ui/PauseMenuScreen.h>

PauseMenuScreen::PauseMenuScreen(
    IScreenNavigator& navigator,
    InputDevices& inputDevices,
    ::Race& race) :
    Screen(ScreenKind::PauseMenu, navigator, inputDevices),
    _selector(LinearMenuItemSelectorOrientation::Vertical),
    Race(race)
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

    if (_inputDevices.Keyboard.IsPressed(VK_ESCAPE))
    {
        Race.Resume();
        _navigator.NavigateTo(ScreenKind::Race);
    }
    else if (
        _inputDevices.Keyboard.IsPressed(VK_RETURN) ||
        _inputDevices.Keyboard.IsPressed(VK_SPACE) ||
        _inputDevices.Joystick.IsButton1Pressed())
    {
        if (GetSelectedItem() == PauseMenuItem::Resume)
        {
            Race.Resume();
            _navigator.NavigateTo(ScreenKind::Race);
        }
        else if (GetSelectedItem() == PauseMenuItem::StartMenu)
        {
            _navigator.NavigateTo(ScreenKind::StartMenu);
        }
    }
}
