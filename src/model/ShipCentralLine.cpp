#include <model/ShipCentralLine.h>

ShipCentralLine::ShipCentralLine()
{
    Init();
}

void ShipCentralLine::Init()
{
    Front.Set(0.0f, 0.0f, 0.0f);
    Rear.Set(0.0f, 0.0f, 0.0f);
    NormalFront.Set(0.0f, 0.0f, 0.0f);
    NormalRear.Set(0.0f, 0.0f, 0.0f);
    TrackPointIndexFront = 0;
    TrackPointIndexRear = 0;
}
