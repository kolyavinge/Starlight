#include <lib/Assert.h>
#include <lib/String.h>
#include <lib/di/DependencyContainer.h>
#include <game/inject/CoreInjectModule.h>
#include <game/inject/AIInjectModule.h>
#include <game/inject/RenderInjectModule.h>
#include <game/inject/UIInjectModule.h>
#include <game/inject/VoxInjectModule.h>
#include <game/inject/GameInjectModule.h>
#include <game/GameFactory.h>

Game& GameFactory::MakeNewGame()
{
    CoreInjectModule coreInjectModule;
    AIInjectModule aiInjectModule;
    RenderInjectModule renderInjectModule;
    UIInjectModule uiInjectModule;
    VoxInjectModule voxInjectModule;
    GameInjectModule gameInjectModule;

    DependencyContainer container;
    container.InitFromModule(coreInjectModule);
    container.InitFromModule(aiInjectModule);
    container.InitFromModule(renderInjectModule);
    container.InitFromModule(uiInjectModule);
    container.InitFromModule(voxInjectModule);
    container.InitFromModule(gameInjectModule);

    Game& game = container.Resolve<Game>();
    game.Init();

    String unusedInstances = container.GetUnusedInstancesAsString();
    Assert::True(unusedInstances.GetLength() == 0);

    return game;
}
