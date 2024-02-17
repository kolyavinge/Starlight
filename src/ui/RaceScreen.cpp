#include <windows.h>
#include <core/RaceState.h>
#include <core/ShipController.h>
#include <ui/RaceScreen.h>

RaceScreen::RaceScreen(
    IScreenNavigator& navigator,
    InputDevices& inputDevices,
    ::Race& race) :
    Screen(ScreenKind::Race, navigator, inputDevices),
    Race(race)
{
}

void RaceScreen::Update()
{
    Race.Update();
    Race.Camera.SetFrontView(Race.Player);
    //Race.Camera.SetFrontView(Race.Enemies[0]);
    if (Race.State == RaceState::Finish)
    {
        _navigator.NavigateTo(ScreenKind::Finish);
    }
}

void RaceScreen::ProcessInput()
{
    ShipController& playerController = Race.PlayerController;
    Keyboard& keyboard = _inputDevices.Keyboard;
    Joystick& joystick = _inputDevices.Joystick;

    if (keyboard.IsPressedOrHeld('W') ||
        keyboard.IsPressedOrHeld(VK_UP) ||
        joystick.IsButton1Pressed())
    {
        playerController.ActivateThrottle();
    }
    else
    {
        playerController.ReleaseThrottle();
    }

    if (keyboard.IsPressedOrHeld('S') ||
        keyboard.IsPressedOrHeld(VK_DOWN) ||
        joystick.IsButton2Pressed() ||
        joystick.IsButton3Pressed())
    {
        playerController.ActivateBreak();
    }
    else
    {
        playerController.ReleaseBreak();
    }

    if (keyboard.IsPressedOrHeld('A') ||
        keyboard.IsPressedOrHeld(VK_LEFT) ||
        joystick.IsLeftPressed())
    {
        playerController.TurnLeft();
    }
    else if (
        keyboard.IsPressedOrHeld('D') ||
        keyboard.IsPressedOrHeld(VK_RIGHT) ||
        joystick.IsRightPressed())
    {
        playerController.TurnRight();
    }
    else
    {
        playerController.ReleaseTurn();
    }

    if (keyboard.IsPressed(VK_ESCAPE))
    {
        Race.Pause();
        _navigator.NavigateTo(ScreenKind::PauseMenu);
    }
}
