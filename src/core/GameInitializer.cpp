#include <calc/Vector3.h>
#include <core/PositionUpdater.h>
#include <core/GameInitializer.h>

void GameInitializer::Init(Game& game)
{
    game.Track.Init();
    SetPlayerBehindStartFinishLine(game);
    game.Player.CentralLine.TrackPointIndexFront = game.Track.StartFinishLineIndex;
    game.Player.CentralLine.TrackPointIndexRear = game.Track.StartFinishLineIndex;
    UpdateShipPosition(game);
}

void GameInitializer::SetPlayerBehindStartFinishLine(Game& game)
{
    int lineIndex = game.Track.StartFinishLineIndex;
    Vector3 middle = game.Track.OutsidePoints[lineIndex];
    middle.Sub(game.Track.InsidePoints[lineIndex]);
    middle.Div(2.0f);
    middle.Add(game.Track.InsidePoints[lineIndex]);
    game.Player.OrientationByFrontPoint(middle, game.Track.StraightDirection);
}

void GameInitializer::UpdateShipPosition(Game& game)
{
    PositionUpdater positionUpdater;
    positionUpdater.Update(game.Player, game.Track);
}
