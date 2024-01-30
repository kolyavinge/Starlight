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

void GameScreen::ProcessInput()
{
    Keyboard& keyboard = _inputDevices.Keyboard;
    Joystick& joystick = _inputDevices.Joystick;

    if (keyboard.IsPressed('W') || keyboard.IsHeld('W') || joystick.IsButton1Pressed())
    {
        _playerController.ActivateThrottle();
    }
    else
    {
        _playerController.ReleaseThrottle();
    }

    if (keyboard.IsPressed('S') || keyboard.IsHeld('S') || joystick.IsButton2Pressed() || joystick.IsButton3Pressed())
    {
        _playerController.ActivateBreak();
    }
    else
    {
        _playerController.ReleaseBreak();
    }

    if (keyboard.IsPressed('A') || keyboard.IsHeld('A') || joystick.IsLeftPressed())
    {
        _playerController.TurnLeft();
    }
    else if (keyboard.IsPressed('D') || keyboard.IsHeld('D') || joystick.IsRightPressed())
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
