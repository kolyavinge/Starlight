#include "core/Game.h"

Game::Game(
    Ship& player,
    Track& track,
    GameUpdater& gameUpdater,
    Controller& controller,
    GameCamera& camera) :
    Player(player),
    CurrentTrack(track),
    _gameUpdater(gameUpdater),
    PlayerController(controller),
    Camera(camera)
{
}

void Game::Update()
{
    _gameUpdater.Update();
}
