#include <lib/Random.h>
#include <model/ShipAIData.h>

void ShipMovingDirections::Init()
{
    AvailableDirections.Clear();
    EnabledDirections.Clear();
    ResultDirection.Set(0.0f, 0.0f, 0.0f);
}

ShipAIData::ShipAIData()
{
    MovingDirections.Init();
    MovingPointsSteps = 0;
    StraightDirectionLimit = 0.0f;
    MovingDirectionLength = 0.0f;
    VelocityDelta = 0.0f;
    WeaponFireIterations = 0;
}

void ShipAIData::InitForPlayer()
{
    MovingDirections.Init();

    Random rand;
    MovingPointsSteps = 8 + rand.GetIntFromZeroToN(4);
    StraightDirectionLimit = 0.98f + rand.GetFloatFromZeroToN(0.02f);
    MovingDirectionLength = 15.0f + (float)rand.GetIntFromZeroToN(5);
    WeaponFireIterations = 0;
}

void ShipAIData::InitForEnemy()
{
    InitForPlayer();

    Random rand;
    VelocityDelta = 0.1f + rand.GetFloatFromZeroToN(0.05f);
}
