#include <calc/Vector3d.h>
#include <model/Track.h>
#include <core/PositionUpdater.h>
#include <core/GameInitializer.h>

void GameInitializer::Init(Game& game)
{
    game.CurrentTrack.Init();
    SetPlayerByStartFinishLine(game);
    game.Player.CentralLine.TrackPointIndexFront = game.CurrentTrack.StartFinishLineIndex;
    game.Player.CentralLine.TrackPointIndexRear = game.CurrentTrack.StartFinishLineIndex;
    UpdateShipPosition(game);
}

void GameInitializer::SetPlayerByStartFinishLine(Game& game)
{
    int i = game.CurrentTrack.StartFinishLineIndex;
    Track& track = game.CurrentTrack;
    Vector3d middle = track.OutsidePoints[i];
    middle.Sub(track.InsidePoints[i]);
    middle.Div(2.0f);
    middle.Add(track.InsidePoints[i]);
    game.Player.OrientationByFrontPoint(middle, track.StraightDirection);
}

void GameInitializer::UpdateShipPosition(Game& game)
{
    PositionUpdater positionUpdater;
    positionUpdater.Update(game.Player, game.CurrentTrack);
}
