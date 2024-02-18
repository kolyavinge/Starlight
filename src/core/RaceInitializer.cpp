#include <calc/Vector3.h>
#include <model/Track.h>
#include <core/RaceInitializer.h>

void RaceInitializer::Init(Race& race)
{
    InitShip(race.Player, *race.Track);
    for (int i = 0; i < race.Enemies.Count(); i++)
    {
        InitShip(race.Enemies[i], *race.Track);
    }
}

void RaceInitializer::InitShip(Ship& ship, Track& track)
{
    ship.Init();
    SetShipBehindStartFinishLine(ship, track);
    ship.CentralLine.TrackPointIndexFront = track.StartFinishLineIndex;
    ship.CentralLine.TrackPointIndexRear = track.StartFinishLineIndex;
    _positionUpdater.Update(ship, track);
}

void RaceInitializer::SetShipBehindStartFinishLine(Ship& ship, Track& track)
{
    int lineIndex = track.StartFinishLineIndex;
    Vector3 middle = track.OutsidePoints[lineIndex];
    middle.Sub(track.InsidePoints[lineIndex]);
    middle.Div(2.0f);
    middle.Add(track.InsidePoints[lineIndex]);
    ship.OrientationByFrontPoint(middle, track.StraightDirection);
}
