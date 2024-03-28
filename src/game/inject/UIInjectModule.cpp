#include <ui/FinishScreen.h>
#include <ui/PauseMenuScreen.h>
#include <ui/RacePreparationScreen.h>
#include <ui/RaceScreen.h>
#include <ui/ScreenManager.h>
#include <ui/StartMenuScreen.h>
#include <ui/TrackSelectorScreen.h>
#include <game/inject/UIInjectModule.h>

void UIInjectModule::Init(Binder& binder)
{
    binder.BindSingletonByFactory<FinishScreen, FinishScreenResolvingFactory>();
    binder.BindSingletonByFactory<PauseMenuScreen, PauseMenuScreenResolvingFactory>();
    binder.BindSingletonByFactory<RacePreparationScreen, RacePreparationScreenResolvingFactory>();
    binder.BindSingletonByFactory<RaceScreen, RaceScreenResolvingFactory>();
    binder.BindSingletonByFactory<ScreenManager, ScreenManagerResolvingFactory>();
    binder.BindSingletonByFactory<StartMenuScreen, StartMenuScreenResolvingFactory>();
    binder.BindSingletonByFactory<TrackSelectorScreen, TrackSelectorScreenResolvingFactory>();
}
