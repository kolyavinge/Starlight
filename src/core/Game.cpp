#include <core/Game.h>

Game::Game(
    Ship& player,
    ::Track& track,
    GameUpdater& gameUpdater,
    Controller& controller,
    ::Camera& camera) :
    _gameUpdater(gameUpdater),
    _currentGameUpdater(&gameUpdater),
    Player(player),
    Track(track),
    PlayerController(controller),
    Camera(camera)
{
    _isPaused = false;
}

void Game::Update()
{
    _currentGameUpdater->Update();
}

void Game::SwitchPause()
{
    _isPaused = !_isPaused;
    _currentGameUpdater = _isPaused ? (IGameUpdater*)&_emptyGameUpdater : &_gameUpdater;
}
