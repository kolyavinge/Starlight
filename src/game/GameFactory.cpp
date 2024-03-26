#include <lib/di/DependencyContainer.h>
#include <game/CoreInjectModule.h>
#include <game/AIInjectModule.h>
#include <game/GameFactory.h>

Game& GameFactory::MakeNewGame()
{
    CoreInjectModule coreInjectModule;
    AIInjectModule aiInjectModule;

    DependencyContainer container;
    container.InitFromModule(coreInjectModule);
    container.InitFromModule(aiInjectModule);

    container.BindSingletonByFactory<Game, GameResolvingFactory>();

    Game& game = container.Resolve<Game>();
    game.Init();

    return game;
}
