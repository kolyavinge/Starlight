#include <ui/Screen.h>
#include <game/Game.h>

Game::Game(
    TrackManager& trackManager,
    ScreenNavigator& screenNavigator,
    ::InputDevices& inputDevices,
    ::Race& race) :
    _trackManager(trackManager),
    _screenNavigator(screenNavigator),
    _screenManager(screenNavigator, inputDevices, trackManager, race),
    InputDevices(inputDevices),
    Race(race)
{
}

void Game::Init()
{
    _trackManager.Init();
    _renderManager.Init();
    _voxManager.Init();
    _screenNavigator.Init(_screenManager, _renderManager, _voxManager);
    _screenNavigator.NavigateTo(ScreenKind::StartMenu);
}

void Game::Update()
{
    InputDevices.Keyboard.Update();
    Screen& currentScreen = _screenManager.GetCurrentScreen();
    currentScreen.Update();
    currentScreen.ProcessInput();
}

void Game::RenderCurrentScreen()
{
    Screen& currentScreen = _screenManager.GetCurrentScreen();
    _renderManager.GetScreenRenderer(currentScreen).Render(currentScreen);
}

void Game::VoiceCurrentScreen()
{
    Screen& currentScreen = _screenManager.GetCurrentScreen();
    _voxManager.GetScreenVox(currentScreen).Voice(currentScreen);
}

Game* GameResolvingFactory::Make(Resolver& resolver)
{
    return new Game(
        resolver.Resolve<TrackManager>(),
        resolver.Resolve<ScreenNavigator>(),
        resolver.Resolve<InputDevices>(),
        resolver.Resolve<Race>());
}
