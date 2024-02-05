#include <lib/Math.h>
#include <ui/RacePreparationScreen.h>

RacePreparationScreen::RacePreparationScreen(
    IScreenNavigator& navigator,
    InputDevices& inputDevices,
    ::Race& race) :
    Screen(ScreenKind::RacePreparation, navigator, inputDevices),
    Race(race)
{
    _iterationsCount = 200;
    _radiansStep = Math::Pi / (float)_iterationsCount;
}

void RacePreparationScreen::Activate()
{
    Race.Camera.SetFrontView(Race.Player);
    Race.Camera.RotateBy(Math::Pi);
}

void RacePreparationScreen::Update()
{
    Race.Camera.RotateBy(_radiansStep);
    _iterationsCount--;
    if (_iterationsCount == 0)
    {
        _navigator.NavigateToRace();
    }
}

void RacePreparationScreen::ProcessInput()
{
}
