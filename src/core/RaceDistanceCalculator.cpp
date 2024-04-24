#include <core/RaceDistanceCalculator.h>

void RaceDistanceCalculator::InitBeforeStart(IArray<Ship*>& allShips, Track& track)
{
    for (int i = 0; i < allShips.GetCount(); i++)
    {
        Ship& ship = *allShips[i];
        ship.CompletedRaceDistance = ship.CentralLine.TrackPointIndexFront - track.StartFinishLineIndex;
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
