#include <lib/Math.h>
#include <ui/RacePreparationScreen.h>

RacePreparationScreen::RacePreparationScreen(
    IScreenNavigator& navigator,
    InputDevices& inputDevices,
    Camera& camera,
    Race& race) :
    Screen(ScreenKind::RacePreparation, navigator, inputDevices),
    _iterationsCount(3 * 60),
    _camera(camera),
    _race(race)
{
    _currentIteration = 0;
    _radiansStep = Math::Pi / (float)_iterationsCount;
    _countdownNumber = 0;
    _countdownSwitchIteration = _iterationsCount / 3;
    _countdownIteration = 0;
}

void RacePreparationScreen::Activate(Screen*)
{
    _currentIteration = 0;
    _camera.SetFrontView(_race.Player);
    _camera.RotateBy(Math::Pi);
    _countdownNumber = 3;
    _countdownIteration = 0;
}

void RacePreparationScreen::Update()
{
    _camera.RotateBy(_radiansStep);

    _countdownIteration++;
    if (_countdownIteration >= _countdownSwitchIteration)
    {
        _countdownNumber--;
        _countdownIteration = 0;
    }

    _currentIteration++;
    if (_currentIteration == _iterationsCount)
    {
        _race.Start();
        _navigator.NavigateTo(ScreenKind::Race);
    }
}

int RacePreparationScreen::GetCountdownNumber()
{
    return _countdownNumber;
}

int RacePreparationScreen::GetCountdownIteration()
{
    return _countdownIteration;
}

int RacePreparationScreen::GetCountdownSwitchIteration()
{
    return _countdownSwitchIteration;
}

RacePreparationScreen* RacePreparationScreenResolvingFactory::Make(Resolver& resolver)
{
    return new RacePreparationScreen(
        resolver.Resolve<IScreenNavigator>(),
        resolver.Resolve<InputDevices>(),
        resolver.Resolve<Camera>(),
        resolver.Resolve<Race>());
}
