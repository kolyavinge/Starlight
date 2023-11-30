#include "core/Game.h"

Game::Game(
    GameUpdater& gameUpdater,
    Controller& controller) :
    _gameUpdater(gameUpdater),
    PlayerController(controller)
{
}

void Game::Update()
{
    _gameUpdater.Update();
}
