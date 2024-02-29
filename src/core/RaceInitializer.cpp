#include <lib/List.h>
#include <calc/Vector3.h>
#include <model/Ship.h>
#include <model/ShipMeasure.h>
#include <model/Track.h>
#include <core/PositionUpdater.h>
#include <core/RaceInitializer.h>

void RaceInitializer::Init(Race& race)
{
    InitShips(race);
    SetStartGrid(race);
    UpdateShipsPositions(race);
    SetAIData(race);
}

void RaceInitializer::InitShips(Race& race)
{
    race.Player.Init();
    for (int i = 0; i < race.Enemies.GetCount(); i++)
    {
        race.Enemies[i].Init();
    }
}

void RaceInitializer::SetStartGrid(Race& race)
{
    Track& track = *race.Track;
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

    Vector3 trackOppositeDirection(track.StraightDirection);
    trackOppositeDirection.Mul(-1.0f);
    trackOppositeDirection.SetLength(2.0f * ShipMeasure::YLength);

    List<Ship*> ships;
    for (int i = 0; i < race.Enemies.GetCount(); i++)
    {
        ships.Add(&race.Enemies[i]);
    }
    ships.Add(&race.Player);

    int shipIndex = 0;
    const int rowsCount = ships.GetCount() / 2;
    for (int row = 0; row < rowsCount; row++)
    {
        ships[shipIndex++]->OrientationByFrontPoint(firstRowPoint, track.StraightDirection);
        ships[shipIndex++]->OrientationByFrontPoint(secondRowPoint, track.StraightDirection);
        firstRowPoint.Add(trackOppositeDirection);
        secondRowPoint.Add(trackOppositeDirection);
    }
}

void RaceInitializer::UpdateShipsPositions(Race& race)
{
    PositionUpdater positionUpdater;
    positionUpdater.Update(race.Player, *race.Track);
    for (int i = 0; i < race.Enemies.GetCount(); i++)
    {
        positionUpdater.Update(race.Enemies[i], *race.Track);
    }
}

void RaceInitializer::SetAIData(Race& race)
{
    for (int i = 0; i < race.Enemies.GetCount(); i++)
    {
        race.Enemies[i].AIData.Init();
    }
}
