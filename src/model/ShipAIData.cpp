#include <lib/Random.h>
#include <model/ShipAIData.h>

ShipAIData::ShipAIData()
{
    MovingDirection.Set(0.0f, 0.0f, 0.0f);
    MovingPointsSteps = 0;
    StraightDirectionLimit = 0.0f;
    MovingDirectionLength = 0.0f;
    VelocityDelta = 0.0f;
}

void ShipAIData::InitForPlayer()
{
    MovingDirection.Set(0.0f, 0.0f, 0.0f);

    Random rand;
    MovingPointsSteps = rand.GetIntFromZeroToN(5) + 5;
    StraightDirectionLimit = rand.GetFloatFromZeroToN(0.02f) + 0.98f;
    MovingDirectionLength = (float)rand.GetIntFromZeroToN(5) + 5.0f;
}

void ShipAIData::InitForEnemy()
{
    InitForPlayer();

    Random rand;
    VelocityDelta = 0.1f + rand.GetFloatFromZeroToN(0.05f);
}
