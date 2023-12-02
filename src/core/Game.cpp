#include "core/Game.h"

Game::Game(
    Ship& player,
    Track& track,
    GameUpdater& gameUpdater,
    Controller& controller) :
    Player(player),
    CurrentTrack(track),
    _gameUpdater(gameUpdater),
    PlayerController(controller)
{
}

void Game::Update()
{
    _gameUpdater.Update();
}
