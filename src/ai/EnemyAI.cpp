#include <calc/Vector3.h>
#include <ai/EnemyAI.h>

void EnemyAI::ApplyFor(IArray<Ship>& enemies, IArray<Ship*>& allShips, Track& track)
{
    for (int i = 0; i < enemies.GetCount(); i++)
    {
        ApplyFor(enemies[i], allShips, track);
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
}
