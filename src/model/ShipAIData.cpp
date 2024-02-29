#include <lib/Random.h>
#include <model/ShipAIData.h>

ShipAIData::ShipAIData()
{
    Init();
}

void ShipAIData::Init()
{
    MovingDirection.Set(0.0f, 0.0f, 0.0f);

    Random rand;
    MovingPointsSteps = rand.GetIntFromZeroToN(5) + 5;
    StraightDirectionLimit = rand.GetFloatFromZeroToN(0.02f) + 0.98f;
    MovingDirectionLength = (float)rand.GetIntFromZeroToN(5) + 5.0f;
}
