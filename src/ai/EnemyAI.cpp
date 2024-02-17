#include <ai/EnemyAI.h>

void EnemyAI::Update(List<Ship>& enemies, Track& track)
{
    for (int i = 0; i < enemies.Count(); i++)
    {
        Update(enemies[i], track);
    }
}

void EnemyAI::Update(Ship& enemy, Track& track)
{
    enemy.AIMovingDirection = _obstacleAvoidanceLogic.GetMovingDirection(enemy, track);
    _steeringLogic.Update(enemy);
}
