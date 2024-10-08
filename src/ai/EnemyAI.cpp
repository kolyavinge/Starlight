#include <ai/EnemyAI.h>

EnemyAI::EnemyAI(
    ObstacleAvoidanceLogic& obstacleAvoidanceLogic,
    SteeringLogic& steeringLogic,
    NitroActivationLogic& nitroActivationLogic,
    WeaponActivationLogic& weaponActivationLogic) :
    _obstacleAvoidanceLogic(obstacleAvoidanceLogic),
    _steeringLogic(steeringLogic),
    _nitroActivationLogic(nitroActivationLogic),
    _weaponActivationLogic(weaponActivationLogic)
{
}

void EnemyAI::ApplyFor(Collection<Ship>& enemies, Collection<Ship*>& allShips, Track& track)
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

void EnemyAI::ApplyFor(Ship& enemy, Collection<Ship*>& allShips, Track& track)
{
    _obstacleAvoidanceLogic.CalculateMovingDirection(enemy, allShips, track);
    _steeringLogic.Update(enemy, track);
    _nitroActivationLogic.Apply(enemy, track);
    _weaponActivationLogic.Apply(enemy, allShips);
}

EnemyAI* EnemyAIResolvingFactory::Make(Resolver& resolver)
{
    return new EnemyAI(
        resolver.Resolve<ObstacleAvoidanceLogic>(),
        resolver.Resolve<SteeringLogic>(),
        resolver.Resolve<NitroActivationLogic>(),
        resolver.Resolve<WeaponActivationLogic>());
}
