#include <ui/FinishScreen.h>

FinishScreen::FinishScreen(
    IScreenNavigator& navigator,
    InputDevices& inputDevices,
    EnemyAI& enemyAI,
    ::Race& race) :
    Screen(ScreenKind::Finish, navigator, inputDevices),
    IterationsCount(400),
    _enemyAI(enemyAI),
    Race(race)
{
    _iterationCount = 0;
}

void FinishScreen::Activate(Screen*)
{
    _iterationCount = 0;
    Race.Camera.SetFrontView(Race.Player);
}

void FinishScreen::Update()
{
    if (_iterationCount < IterationsCount)
    {
        _enemyAI.ApplyFor(Race.Player, Race.AllShips, *Race.Track);
        Race.Update();
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
        resolver.Resolve<EnemyAI>(),
        resolver.Resolve<Race>());
}
