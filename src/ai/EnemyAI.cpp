#include <calc/Vector3.h>
#include <ai/EnemyAI.h>

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
    Vector3 newMovingDirection = _obstacleAvoidanceLogic.GetMovingDirection(enemy, allShips, track);
    if (!newMovingDirection.IsZero())
    {
        enemy.AIData.MovingDirection = newMovingDirection;
    }
    _steeringLogic.Update(enemy);
    _nitroActivationLogic.Apply(enemy, track);
}
