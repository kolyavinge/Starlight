#include <windows.h>
#include <core/RaceState.h>
#include <core/ShipController.h>
#include <ui/RaceScreen.h>

RaceScreen::RaceScreen(
    IScreenNavigator& navigator,
    InputDevices& inputDevices,
    Camera& camera,
    Race& race) :
    Screen(ScreenKind::Race, navigator, inputDevices),
    _camera(camera),
    _race(race)
{
}

void RaceScreen::Update()
{
    _race.Update();
    if (_race.Player.State != ShipState::Destroyed)
    {
        _camera.SetFrontView(_race.Player);
    }
    //_camera.SetFrontView(Race.Enemies[0]);
    if (_race.State == RaceState::Finish)
    {
        _navigator.NavigateTo(ScreenKind::Finish);
    }
}

void RaceScreen::ProcessInput()
{
    ShipController& playerController = _race.PlayerController;
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

    if ((keyboard.IsPressedOrHeld('Q') ||
        joystick.IsButton4Pressed()) &&
        _race.Player.State != ShipState::Destroyed)
    {
        _camera.SetRearView(_race.Player);
    }

    if (keyboard.IsPressedOrHeld(VK_SPACE))
    {
        playerController.ActivateFire();
    }
    else
    {
        playerController.ReleaseFire();
    }

    if (keyboard.IsPressed('N'))
    {
        playerController.ActivateNitro();
    }

    if (keyboard.IsPressed(VK_BACK))
    {
        playerController.Reset();
    }

    if (keyboard.IsPressed(VK_ESCAPE))
    {
        _race.Pause();
        _navigator.NavigateTo(ScreenKind::PauseMenu);
    }
}

RaceScreen* RaceScreenResolvingFactory::Make(Resolver& resolver)
{
    return new RaceScreen(
        resolver.Resolve<IScreenNavigator>(),
        resolver.Resolve<InputDevices>(),
        resolver.Resolve<Camera>(),
        resolver.Resolve<Race>());
}
