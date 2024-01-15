#include <calc/Vector3.h>
#include <model/Track.h>
#include <core/PositionUpdater.h>
#include <core/GameInitializer.h>

void GameInitializer::Init(Game& game)
{
    game.Track.Init();
    SetPlayerByStartFinishLine(game);
    game.Player.CentralLine.TrackPointIndexFront = game.Track.StartFinishLineIndex;
    game.Player.CentralLine.TrackPointIndexRear = game.Track.StartFinishLineIndex;
    UpdateShipPosition(game);
}

void GameInitializer::SetPlayerByStartFinishLine(Game& game)
{
    int i = game.Track.StartFinishLineIndex;
    Track& track = game.Track;
    Vector3 middle = track.OutsidePoints[i];
    middle.Sub(track.InsidePoints[i]);
    middle.Div(2.0f);
    middle.Add(track.InsidePoints[i]);
    game.Player.OrientationByFrontPoint(middle, track.StraightDirection);
}

void GameInitializer::UpdateShipPosition(Game& game)
{
    PositionUpdater positionUpdater;
    positionUpdater.Update(game.Player, game.Track);
}
