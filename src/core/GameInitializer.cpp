#include <calc/Vector3d.h>
#include <model/Track.h>
#include <core/ZCalculator.h>
#include <core/GameInitializer.h>

void GameInitializer::Init(Game& game)
{
    game.CurrentTrack.Init();
    SetPlayerByStartFinishLine(game);
    CalculateZ(game);
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

void GameInitializer::CalculateZ(Game& game)
{
    ZCalculator zCalculator;
    zCalculator.CalculateZ(game.Player, game.CurrentTrack);
}
