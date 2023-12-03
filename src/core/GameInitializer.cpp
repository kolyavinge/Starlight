#include "calc/Vector3d.h"
#include "model/Track.h"
#include "core/GameInitializer.h"

void GameInitializer::Init(Game& game)
{
    game.CurrentTrack.Init();
    InitPlayer(game);
}

void GameInitializer::InitPlayer(Game& game)
{
    int i = game.CurrentTrack.StartFinishLineIndex;
    Track& track = game.CurrentTrack;
    Vector3d middle = track.OutsidePoints[i];
    middle.Sub(track.InsidePoints[i]);
    middle.Div(2.0f);
    middle.Add(track.InsidePoints[i]);
    game.Player.SetFrontOrientation(middle, track.StraightDirection);
}
