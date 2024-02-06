#include <lib/Math.h>
#include <ui/RacePreparationScreen.h>

RacePreparationScreen::RacePreparationScreen(
    IScreenNavigator& navigator,
    InputDevices& inputDevices,
    ::Race& race) :
    Screen(ScreenKind::RacePreparation, navigator, inputDevices),
    _iterationsCount(200),
    Race(race)
{
    _currentIteration = 0;
    _radiansStep = Math::Pi / (float)_iterationsCount;
}

void RacePreparationScreen::Activate()
{
    _currentIteration = _iterationsCount;
    Race.Camera.SetFrontView(Race.Player);
    Race.Camera.RotateBy(Math::Pi);
}

void RacePreparationScreen::Update()
{
    Race.Camera.RotateBy(_radiansStep);
    _currentIteration--;
    if (_currentIteration == 0)
    {
        _navigator.NavigateTo(ScreenKind::Race);
    }
}

void RacePreparationScreen::ProcessInput()
{
}
