#include <gl/opengl.h>
#include <lib/Exceptions.h>
#include <calc/Vector3.h>
#include <model/ShipMeasure.h>
#include <render/common/RenderConstants.h>
#include <render/dash/EnemyShipMarkRenderer.h>

void EnemyShipMarkRenderer::Render(Ship& player, Collection<Ship*>& allShips, Track& track)
{
    int playerIndex = GetPlayerIndex(player, allShips);
    CalculateEmenyDisatance(playerIndex, player, allShips);
    RenderMarks(player, track);
}

int EnemyShipMarkRenderer::GetPlayerIndex(Ship& player, Collection<Ship*>& allShips)
{
    for (int i = 0; i < allShips.GetCount(); i++)
    {
        if (Object::ReferenceEquals(player, *allShips[i]))
        {
            return i;
        }
    }

    throw ArgumentException();
}

void EnemyShipMarkRenderer::CalculateEmenyDisatance(int playerIndex, Ship& player, Collection<Ship*>& allShips)
{
    for (int i = playerIndex + 1; i < allShips.GetCount(); i++)
    {
        Ship& enemy = *allShips[i];
        Vector3 distance(enemy.CentralLine.Front);
        distance.Sub(player.CentralLine.Rear);
        float length = distance.GetLength();
        if (length < 4 * ShipMeasure::YLength)
        {
            _enemyDistance.Add(distance);
        }
    }
}

void EnemyShipMarkRenderer::RenderMarks(Ship& player, Track& track)
{
    if (_enemyDistance.GetCount() > 0)
    {
        for (int i = 0; i < _enemyDistance.GetCount(); i++)
        {
            RenderMark(i, player, track);
        }

        _enemyDistance.Clear();
    }
}

void EnemyShipMarkRenderer::RenderMark(int markIndex, Ship& player, Track& track)
{
    glPushMatrix();
    glLoadIdentity();

    Vector3 insideDirection(track.InsidePoints[player.CentralLine.TrackPointIndexFront]);
    insideDirection.Sub(player.CentralLine.Front);

    Vector3 outsideDirection(track.OutsidePoints[player.CentralLine.TrackPointIndexFront]);
    outsideDirection.Sub(player.CentralLine.Front);

    Vector3 playerDirection(player.CentralLine.Front);
    playerDirection.Sub(player.CentralLine.Rear);
    playerDirection.VectorProduct(outsideDirection);
    float markX = 0.0f;
    if (playerDirection.Z > 0.0f)
    {
        gluOrtho2D(-outsideDirection.GetLength(), insideDirection.GetLength(), 0.0, 50.0);
        float dot = _enemyDistance[markIndex].DotProduct(insideDirection) / (_enemyDistance[markIndex].GetLength() * insideDirection.GetLength());
        markX = dot * _enemyDistance[markIndex].GetLength();
    }
    else
    {
        gluOrtho2D(-insideDirection.GetLength(), outsideDirection.GetLength(), 0.0, 50.0);
        float dot = _enemyDistance[markIndex].DotProduct(outsideDirection) / (_enemyDistance[markIndex].GetLength() * outsideDirection.GetLength());
        markX = dot * _enemyDistance[markIndex].GetLength();
    }

    glColor4f(RenderConstants::TextColor, RenderConstants::TextColor, RenderConstants::TextColor, 1.0f);

    glBegin(GL_TRIANGLES);
    glVertex2f(markX - 0.3f, 0.0f);
    glVertex2f(markX + 0.3f, 0.0f);
    glVertex2f(markX, 1.0f);
    glEnd();

    glPopMatrix();
}

EnemyShipMarkRenderer* EnemyShipMarkRendererResolvingFactory::Make(Resolver&)
{
    return new EnemyShipMarkRenderer();
}
