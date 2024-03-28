#include <lib/String.h>
#include <lib/di/DependencyContainer.h>
#include <game/CoreInjectModule.h>
#include <game/AIInjectModule.h>
#include <game/RenderInjectModule.h>
#include <game/UIInjectModule.h>
#include <game/GameInjectModule.h>
#include <game/GameFactory.h>

Game& GameFactory::MakeNewGame()
{
    CoreInjectModule coreInjectModule;
    AIInjectModule aiInjectModule;
    RenderInjectModule renderInjectModule;
    UIInjectModule uiInjectModule;
    GameInjectModule gameInjectModule;

    DependencyContainer container;
    container.InitFromModule(coreInjectModule);
    container.InitFromModule(aiInjectModule);
    container.InitFromModule(renderInjectModule);
    container.InitFromModule(uiInjectModule);
    container.InitFromModule(gameInjectModule);

    Game& game = container.Resolve<Game>();
    game.Init();

    String unusedInstances = container.GetUnusedInstancesAsString(); // debug

    return game;
}
