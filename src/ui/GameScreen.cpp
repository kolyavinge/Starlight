#include <windows.h>
#include <ui/GameScreen.h>

GameScreen::GameScreen(
    IScreenNavigator& navigator,
    InputDevices& inputDevices,
    ShipController& playerController,
    IPauseSwitcher& pauseSwitcher) :
    Screen(ScreenKind::Game, navigator, inputDevices),
    _playerController(playerController),
    _pauseSwitcher(pauseSwitcher)
{
}

void GameScreen::Activate()
{
}

void GameScreen::ProcessInput()
{
    Keyboard& keyboard = _inputDevices.Keyboard;
    Joystick& joystick = _inputDevices.Joystick;

    if (keyboard.IsPressedOrHeld('W') ||
        keyboard.IsPressedOrHeld(VK_UP) ||
        joystick.IsButton1Pressed())
    {
        _playerController.ActivateThrottle();
    }
    else
    {
        _playerController.ReleaseThrottle();
    }

    if (keyboard.IsPressedOrHeld('S') ||
        keyboard.IsPressedOrHeld(VK_DOWN) ||
        joystick.IsButton2Pressed() ||
        joystick.IsButton3Pressed())
    {
        _playerController.ActivateBreak();
    }
    else
    {
        _playerController.ReleaseBreak();
    }

    if (keyboard.IsPressedOrHeld('A') ||
        keyboard.IsPressedOrHeld(VK_LEFT) ||
        joystick.IsLeftPressed())
    {
        _playerController.TurnLeft();
    }
    else if (
        keyboard.IsPressedOrHeld('D') ||
        keyboard.IsPressedOrHeld(VK_RIGHT) ||
        joystick.IsRightPressed())
    {
        _playerController.TurnRight();
    }
    else
    {
        _playerController.ReleaseTurn();
    }

    if (keyboard.IsPressed(VK_ESCAPE))
    {
        _pauseSwitcher.SwitchPause();
        _navigator.NavigateToPauseMenu();
    }
}
