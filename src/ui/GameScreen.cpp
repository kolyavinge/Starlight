#include <windows.h>
#include <ui/GameScreen.h>

GameScreen::GameScreen(
    IScreenNavigator& navigator,
    InputDevices& inputDevices,
    ShipController& playerController,
    IPauseSwitcher& pauseSwitcher) :
    Screen(ScreenKind::GameKind, navigator, inputDevices),
    _playerController(playerController),
    _pauseSwitcher(pauseSwitcher)
{
}

void GameScreen::ProcessInput()
{
    Keyboard& keyboard = _inputDevices.Keyboard;
    Joystick& joystick = _inputDevices.Joystick;

    if (keyboard.IsPressed('w') || joystick.IsButton1Pressed())
    {
        _playerController.ActivateThrottle();
    }
    else
    {
        _playerController.ReleaseThrottle();
    }

    if (keyboard.IsPressed('s') || joystick.IsButton2Pressed() || joystick.IsButton3Pressed())
    {
        _playerController.ActivateBreak();
    }
    else
    {
        _playerController.ReleaseBreak();
    }

    if (keyboard.IsPressed('a') || joystick.IsLeftPressed())
    {
        _playerController.TurnLeft();
    }
    else if (keyboard.IsPressed('d') || joystick.IsRightPressed())
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
        keyboard.Release(VK_ESCAPE);
    }
}
