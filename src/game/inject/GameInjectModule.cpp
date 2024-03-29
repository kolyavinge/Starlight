#include <input/InputDevices.h>
#include <game/ScreenNavigator.h>
#include <game/Game.h>
#include <game/inject/GameInjectModule.h>

void GameInjectModule::Init(Binder& binder)
{
    binder.BindSingletonByFactory<InputDevices, InputDevicesResolvingFactory>();
    binder.BindSingletonByFactory<ScreenNavigator, ScreenNavigatorResolvingFactory>();
    binder.BindSingletonByFunction<IScreenNavigator>([](Resolver& resolver) -> IScreenNavigator* { return &resolver.Resolve<ScreenNavigator>(); });
    binder.BindSingletonByFactory<Game, GameResolvingFactory>();
}
