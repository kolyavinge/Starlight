#include <calc/Vector3.h>
#include <core/PositionCorrector.h>

void PositionCorrector::CorrectAfterFloatOperations(Ship& ship)
{
    Vector3 direction = ship.CentralLine.Front;
    direction.Sub(ship.CentralLine.Rear);
    ship.OrientationByFrontPoint(ship.CentralLine.Front, direction);
}

PositionCorrector* PositionCorrectorResolvingFactory::Make(Resolver&)
{
    return new PositionCorrector();
}
