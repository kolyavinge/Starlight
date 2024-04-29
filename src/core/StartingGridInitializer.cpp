#include <lib/List.h>
#include <model/ShipMeasure.h>
#include <core/StartingGridInitializer.h>

void StartingGridInitializer::SetStartGrid(Ship& player, Collection<Ship>& enemies, Track& track)
{
    Vector3 startLineDirection(track.OutsidePoints[track.StartFinishLineIndex]);
    startLineDirection.Sub(track.InsidePoints[track.StartFinishLineIndex]);
    float shipBetweenGap = (startLineDirection.GetLength() - 2.0f * ShipMeasure::XLength) / 3.0f;

    Vector3 firstRowDirection(startLineDirection);
    firstRowDirection.SetLength(shipBetweenGap + ShipMeasure::XLengthHalf);
    Vector3 firstRowPoint(track.InsidePoints[track.StartFinishLineIndex]);
    firstRowPoint.Add(firstRowDirection);

    Vector3 secondRowDirection(startLineDirection);
    secondRowDirection.SetLength(shipBetweenGap + ShipMeasure::XLength + shipBetweenGap + ShipMeasure::XLengthHalf);
    Vector3 secondRowPoint(track.InsidePoints[track.StartFinishLineIndex]);
    secondRowPoint.Add(secondRowDirection);

    Vector3 straightDirection(track.InsidePoints[track.StartFinishLineIndex + 1]);
    straightDirection.Sub(track.InsidePoints[track.StartFinishLineIndex]);

    Vector3 trackOppositeDirection(straightDirection);
    trackOppositeDirection.Mul(-1.0f);
    trackOppositeDirection.SetLength(2.0f * ShipMeasure::YLength);

    List<Ship*> ships;
    for (int i = 0; i < enemies.GetCount(); i++)
    {
        ships.Add(&enemies[i]);
    }
    ships.Add(&player);

    int shipIndex = 0;
    const int rowsCount = ships.GetCount() / 2;
    for (int row = 0; row < rowsCount; row++)
    {
        ships[shipIndex++]->OrientationByFrontPoint(firstRowPoint, straightDirection);
        ships[shipIndex++]->OrientationByFrontPoint(secondRowPoint, straightDirection);
        firstRowPoint.Add(trackOppositeDirection);
        secondRowPoint.Add(trackOppositeDirection);
    }
}

StartingGridInitializer* StartingGridInitializerResolvingFactory::Make(Resolver&)
{
    return new StartingGridInitializer();
}
