#include <ui/FinishScreen.h>

FinishScreen::FinishScreen(
    IScreenNavigator& navigator,
    InputDevices& inputDevices,
    Camera& camera,
    EnemyAI& enemyAI,
    Race& race) :
    Screen(ScreenKind::Finish, navigator, inputDevices),
    IterationsCount(400),
    _camera(camera),
    _enemyAI(enemyAI),
    _race(race)
{
    _iterationCount = 0;
}

void FinishScreen::Activate(Screen*)
{
    _iterationCount = 0;
    _camera.SetFrontView(_race.Player);
}

void FinishScreen::Update()
{
    if (_iterationCount < IterationsCount)
    {
        _enemyAI.ApplyFor(_race.Player, _race.AllShips, *_race.Track);
        _race.Update();
        _iterationCount++;
    }
    else
    {
        _navigator.NavigateTo(ScreenKind::TrackSelector);
    }
}

int FinishScreen::GetCurrentIteration()
{
    return _iterationCount;
}

FinishScreen* FinishScreenResolvingFactory::Make(Resolver& resolver)
{
    return new FinishScreen(
        resolver.Resolve<IScreenNavigator>(),
        resolver.Resolve<InputDevices>(),
        resolver.Resolve<Camera>(),
        resolver.Resolve<EnemyAI>(),
        resolver.Resolve<Race>());
}
