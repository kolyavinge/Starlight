#include <ai/EnemyAI.h>

EnemyAI::EnemyAI(
    ObstacleAvoidanceLogic& obstacleAvoidanceLogic,
    SteeringLogic& steeringLogic,
    NitroActivationLogic& nitroActivationLogic) :
    _obstacleAvoidanceLogic(obstacleAvoidanceLogic),
    _steeringLogic(steeringLogic),
    _nitroActivationLogic(nitroActivationLogic)
{
}

void EnemyAI::ApplyFor(IArray<Ship>& enemies, IArray<Ship*>& allShips, Track& track)
{
    for (int i = 0; i < enemies.GetCount(); i++)
    {
        Ship& enemy = enemies[i];
        if (enemy.State == ShipState::Active)
        {
            ApplyFor(enemy, allShips, track);
        }
    }
}

void EnemyAI::ApplyFor(Ship& enemy, IArray<Ship*>& allShips, Track& track)
{
    _obstacleAvoidanceLogic.CalculateMovingDirection(enemy, allShips, track);
    _steeringLogic.Update(enemy);
    _nitroActivationLogic.Apply(enemy, track);
}

EnemyAI* EnemyAIResolvingFactory::Make(Resolver& resolver)
{
    return new EnemyAI(
        resolver.Resolve<ObstacleAvoidanceLogic>(),
        resolver.Resolve<SteeringLogic>(),
        resolver.Resolve<NitroActivationLogic>());
}
