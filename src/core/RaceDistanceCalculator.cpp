#include <core/RaceDistanceCalculator.h>

void RaceDistanceCalculator::InitBeforeStart(IArray<Ship*>& allShips, Track& track)
{
    for (int shipIndex = 0; shipIndex < allShips.GetCount(); shipIndex++)
    {
        Ship& ship = *allShips[shipIndex];
        for (int pointIndex = ship.CentralLine.TrackPointIndexFront; pointIndex != track.StartFinishLineIndex; pointIndex = track.GetNextTrackPointIndex(pointIndex))
        {
            ship.CompletedRaceDistance--;
        }
    }
}

void RaceDistanceCalculator::CalculateRaceDistance(Ship& ship, Track& track)
{
    if (ship.CentralLine.TrackPointIndexFront == ship.CentralLine.TrackPointIndexRear)
    {
        return;
    }

    if (track.IsShipMovingInStraightDirection(ship.CentralLine.TrackPointIndexFront, ship.CentralLine.TrackPointIndexRear))
    {
        for (int i = ship.PrevCentralLine.TrackPointIndexFront; i != ship.CentralLine.TrackPointIndexFront; i = track.GetNextTrackPointIndex(i))
        {
            ship.CompletedRaceDistance++;
        }
    }
    else
    {
        for (int i = ship.PrevCentralLine.TrackPointIndexFront; i != ship.CentralLine.TrackPointIndexFront; i = track.GetPrevTrackPointIndex(i))
        {
            ship.CompletedRaceDistance--;
        }
    }
}

RaceDistanceCalculator* RaceDistanceCalculatorResolvingFactory::Make(Resolver&)
{
    return new RaceDistanceCalculator();
}
