#include <lib/Assert.h>
#include <core/RaceDistanceCalculator.h>

void RaceDistanceCalculator::InitBeforeStart(Collection<Ship*>& allShips, Track& track)
{
    for (int shipIndex = 0; shipIndex < allShips.GetCount(); shipIndex++)
    {
        Ship& ship = *allShips[shipIndex];
        for (int pointIndex = track.StartFinishLineIndex; pointIndex != ship.CentralLine.TrackPointIndexFront; pointIndex = track.GetPrevTrackPointIndex(pointIndex))
        {
            ship.CompletedRaceDistance--;
        }
        Assert::Between(ship.CompletedRaceDistance, -20, 20);
    }
}

void RaceDistanceCalculator::CalculateRaceDistance(Ship& ship, Track& track)
{
    if (ship.CentralLine.TrackPointIndexFront == ship.CentralLine.TrackPointIndexRear)
    {
        return;
    }

    int raceDistance = 0;
    if (track.IsShipMovingInStraightDirection(ship.CentralLine.TrackPointIndexFront, ship.CentralLine.TrackPointIndexRear))
    {
        for (int i = ship.PrevCentralLine.TrackPointIndexFront; i != ship.CentralLine.TrackPointIndexFront; i = track.GetNextTrackPointIndex(i))
        {
            raceDistance++;
        }
    }
    else
    {
        for (int i = ship.PrevCentralLine.TrackPointIndexFront; i != ship.CentralLine.TrackPointIndexFront; i = track.GetPrevTrackPointIndex(i))
        {
            raceDistance--;
        }
    }

    Assert::Between(raceDistance, -20, 20);

    ship.CompletedRaceDistance += raceDistance;
}

RaceDistanceCalculator* RaceDistanceCalculatorResolvingFactory::Make(Resolver&)
{
    return new RaceDistanceCalculator();
}
