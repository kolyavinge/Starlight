#include <calc/Vector3.h>
#include <model/Track.h>
#include <core/PositionUpdater.h>
#include <core/RaceInitializer.h>

void RaceInitializer::Init(Race& race)
{
    Track& track = *race.Track;
    track.Init();
    race.Player.Init();
    SetPlayerBehindStartFinishLine(*race.Track, race.Player);
    race.Player.CentralLine.TrackPointIndexFront = track.StartFinishLineIndex;
    race.Player.CentralLine.TrackPointIndexRear = track.StartFinishLineIndex;
    UpdateShipPosition(*race.Track, race.Player);
}

void RaceInitializer::SetPlayerBehindStartFinishLine(Track& track, Ship& player)
{
    int lineIndex = track.StartFinishLineIndex;
    Vector3 middle = track.OutsidePoints[lineIndex];
    middle.Sub(track.InsidePoints[lineIndex]);
    middle.Div(2.0f);
    middle.Add(track.InsidePoints[lineIndex]);
    player.OrientationByFrontPoint(middle, track.StraightDirection);
}

void RaceInitializer::UpdateShipPosition(Track& track, Ship& player)
{
    PositionUpdater positionUpdater;
    positionUpdater.Update(player, track);
}
