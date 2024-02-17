#include <calc/Vector3.h>
#include <model/Track.h>
#include <core/PositionUpdater.h>
#include <core/RaceInitializer.h>

void RaceInitializer::Init(Race& race)
{
    Track& track = *race.Track;
    InitShip(track, race.Player);
    for (int i = 0; i < race.Enemies.Count(); i++)
    {
        InitShip(track, race.Enemies[i]);
    }
}

void RaceInitializer::InitShip(Track& track, Ship& ship)
{
    ship.Init();
    SetPlayerBehindStartFinishLine(track, ship);
    ship.CentralLine.TrackPointIndexFront = track.StartFinishLineIndex;
    ship.CentralLine.TrackPointIndexRear = track.StartFinishLineIndex;
    UpdateShipPosition(track, ship);
}

void RaceInitializer::SetPlayerBehindStartFinishLine(Track& track, Ship& ship)
{
    int lineIndex = track.StartFinishLineIndex;
    Vector3 middle = track.OutsidePoints[lineIndex];
    middle.Sub(track.InsidePoints[lineIndex]);
    middle.Div(2.0f);
    middle.Add(track.InsidePoints[lineIndex]);
    ship.OrientationByFrontPoint(middle, track.StraightDirection);
}

void RaceInitializer::UpdateShipPosition(Track& track, Ship& ship)
{
    PositionUpdater positionUpdater;
    positionUpdater.Update(ship, track);
}
