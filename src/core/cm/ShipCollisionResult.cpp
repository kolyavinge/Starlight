#include <core/cm/ShipCollisionResult.h>

ShipCollisionResult::ShipCollisionResult()
{
    Init();
}

void ShipCollisionResult::Init()
{
    Ship1 = nullptr;
    Ship2 = nullptr;
}
