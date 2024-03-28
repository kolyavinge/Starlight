#include <lib/Math.h>
#include <ui/RacePreparationScreen.h>

RacePreparationScreen::RacePreparationScreen(
    IScreenNavigator& navigator,
    InputDevices& inputDevices,
    ::Race& race) :
    Screen(ScreenKind::RacePreparation, navigator, inputDevices),
    _iterationsCount(3 * 60),
    Race(race)
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
    Race.Camera.SetFrontView(Race.Player);
    Race.Camera.RotateBy(Math::Pi);
    _countdownNumber = 3;
    _countdownIteration = 0;
}

void RacePreparationScreen::Update()
{
    Race.Camera.RotateBy(_radiansStep);

    _countdownIteration++;
    if (_countdownIteration >= _countdownSwitchIteration)
    {
        _countdownNumber--;
        _countdownIteration = 0;
    }

    _currentIteration++;
    if (_currentIteration == _iterationsCount)
    {
        Race.Start();
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
        resolver.Resolve<Race>());
}
