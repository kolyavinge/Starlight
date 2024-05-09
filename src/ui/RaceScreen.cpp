#include <input/Keys.h>
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
        keyboard.IsPressedOrHeld(Keys::Up) ||
        joystick.IsButton1Pressed())
    {
        playerController.ActivateThrottle();
    }
    else
    {
        playerController.ReleaseThrottle();
    }

    if (keyboard.IsPressedOrHeld('S') ||
        keyboard.IsPressedOrHeld(Keys::Down) ||
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
        keyboard.IsPressedOrHeld(Keys::Left) ||
        joystick.IsLeftPressed())
    {
        playerController.TurnLeft();
    }
    else if (
        keyboard.IsPressedOrHeld('D') ||
        keyboard.IsPressedOrHeld(Keys::Right) ||
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

    if (keyboard.IsPressedOrHeld(Keys::Space))
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

    if (keyboard.IsPressed(Keys::Back))
    {
        playerController.Reset();
    }

    if (keyboard.IsPressed(Keys::Escape))
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
