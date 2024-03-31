#include <ai/EnemyAI.h>
#include <ai/NitroActivationLogic.h>
#include <ai/ObstacleAvoidanceLogic.h>
#include <ai/SteeringLogic.h>
#include <ai/WeaponActivationLogic.h>
#include <game/inject/AIInjectModule.h>

void AIInjectModule::Init(Binder& binder)
{
    binder.BindSingletonByFactory<EnemyAI, EnemyAIResolvingFactory>();
    binder.BindSingletonByFactory<NitroActivationLogic, NitroActivationLogicResolvingFactory>();
    binder.BindSingletonByFactory<ObstacleAvoidanceLogic, ObstacleAvoidanceLogicResolvingFactory>();
    binder.BindSingletonByFactory<SteeringLogic, SteeringLogicResolvingFactory>();
    binder.BindSingletonByFactory<WeaponActivationLogic, WeaponActivationLogicResolvingFactory>();
}
