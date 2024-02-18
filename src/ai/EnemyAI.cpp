#include <ai/EnemyAI.h>

void EnemyAI::ApplyFor(List<Ship>& enemies, Track& track)
{
    for (int i = 0; i < enemies.Count(); i++)
    {
        ApplyFor(enemies[i], track);
    }
}

void EnemyAI::ApplyFor(Ship& enemy, Track& track)
{
    enemy.AIMovingDirection = _obstacleAvoidanceLogic.GetMovingDirection(enemy, track);
    _steeringLogic.Update(enemy);
}
