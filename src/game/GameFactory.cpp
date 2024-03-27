#include <lib/di/DependencyContainer.h>
#include <game/CoreInjectModule.h>
#include <game/AIInjectModule.h>
#include <game/RenderInjectModule.h>
#include <game/GameInjectModule.h>
#include <game/GameFactory.h>

Game& GameFactory::MakeNewGame()
{
    CoreInjectModule coreInjectModule;
    AIInjectModule aiInjectModule;
    RenderInjectModule renderInjectModule;
    GameInjectModule gameInjectModule;

    DependencyContainer container;
    container.InitFromModule(coreInjectModule);
    container.InitFromModule(aiInjectModule);
    container.InitFromModule(renderInjectModule);
    container.InitFromModule(gameInjectModule);

    Game& game = container.Resolve<Game>();
    game.Init();

    return game;
}
