#include <ui/Screen.h>
#include <game/Game.h>

Game::Game(
    TrackManager& trackManager,
    ScreenManager& screenManager,
    RenderManager& renderManager,
    VoxManager& voxManager,
    ScreenNavigator& screenNavigator,
    ::InputDevices& inputDevices,
    ::Race& race) :
    _trackManager(trackManager),
    _screenManager(screenManager),
    _renderManager(renderManager),
    _voxManager(voxManager),
    _screenNavigator(screenNavigator),
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
    // Game.Update() вызывается асинхронно - обращаться к текущему экрану нужно напрямую через _screenManager.GetCurrentScreen()
    _screenManager.GetCurrentScreen().Update();
    _screenManager.GetCurrentScreen().ProcessInput();
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
        resolver.Resolve<ScreenManager>(),
        resolver.Resolve<RenderManager>(),
        resolver.Resolve<VoxManager>(),
        resolver.Resolve<ScreenNavigator>(),
        resolver.Resolve<InputDevices>(),
        resolver.Resolve<Race>());
}
