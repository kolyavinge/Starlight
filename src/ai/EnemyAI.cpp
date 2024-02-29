#include <calc/Vector3.h>
#include <ai/EnemyAI.h>

void EnemyAI::ApplyFor(List<Ship>& enemies, List<Ship*>& allShips, Track& track)
{
    for (int i = 0; i < enemies.GetCount(); i++)
    {
        ApplyFor(enemies[i], allShips, track);
    }
}

void EnemyAI::ApplyFor(Ship& enemy, List<Ship*>& allShips, Track& track)
{
    Vector3 newMovingDirection = _obstacleAvoidanceLogic.GetMovingDirection(enemy, allShips, track);
    if (!newMovingDirection.IsZero())
    {
        enemy.AIMovingDirection = newMovingDirection;
    }

    _steeringLogic.Update(enemy);
}
