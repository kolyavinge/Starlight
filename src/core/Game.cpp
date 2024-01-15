#include <core/Game.h>

Game::Game(
    Ship& player,
    ::Track& track,
    GameUpdater& gameUpdater,
    Controller& controller,
    GameCamera& camera) :
    _gameUpdater(gameUpdater),
    Player(player),
    Track(track),
    PlayerController(controller),
    Camera(camera)
{
}

void Game::Update()
{
    _gameUpdater.Update();
}
