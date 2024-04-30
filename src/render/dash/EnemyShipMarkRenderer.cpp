#include <gl/opengl.h>
#include <lib/Exceptions.h>
#include <calc/Vector3.h>
#include <model/ShipMeasure.h>
#include <render/common/RenderConstants.h>
#include <render/dash/EnemyShipMarkRenderer.h>

void EnemyShipMarkRenderer::Render(Ship& player, Collection<Ship*>& allShips, Track& track)
{
    int playerIndex = GetPlayerIndex(player, allShips);
    CalculatePositions(playerIndex, player, allShips);
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

void EnemyShipMarkRenderer::CalculatePositions(int playerIndex, Ship& player, Collection<Ship*>& allShips)
{
    for (int i = playerIndex + 1; i < allShips.GetCount(); i++)
    {
        Ship& enemy = *allShips[i];
        Vector3 distance(enemy.CentralLine.Front);
        distance.Sub(player.CentralLine.Front);
        if (distance.GetLength() < 5 * ShipMeasure::YLength)
        {
            _positions.Add(distance.X);
        }
    }
}

void EnemyShipMarkRenderer::RenderMarks(Ship& player, Track& track)
{
    if (_positions.GetCount() > 0)
    {
        for (int i = 0; i < _positions.GetCount(); i++)
        {
            RenderMark(i, player, track);
        }

        _positions.Clear();
    }
}

void EnemyShipMarkRenderer::RenderMark(int markIndex, Ship& player, Track& track)
{
    glPushMatrix();
    glLoadIdentity();

    Vector3& insideTrackPoint = track.InsidePoints[player.CentralLine.TrackPointIndexFront];
    Vector3& outsideTrackPoint = track.OutsidePoints[player.CentralLine.TrackPointIndexFront];

    Vector3 insideDirection(insideTrackPoint);
    insideDirection.Sub(player.CentralLine.Front);

    Vector3 outsideDirection(outsideTrackPoint);
    outsideDirection.Sub(player.CentralLine.Front);

    Vector3 playerDirection(player.CentralLine.Front);
    playerDirection.Sub(player.CentralLine.Rear);

    insideDirection.VectorProduct(playerDirection);
    if (insideDirection.Z > 0.0f)
    {
        gluOrtho2D(-outsideDirection.GetLength(), insideDirection.GetLength(), 0.0, 50.0);
    }
    else
    {
        gluOrtho2D(-insideDirection.GetLength(), outsideDirection.GetLength(), 0.0, 50.0);
    }

    glColor4f(RenderConstants::TextColor, RenderConstants::TextColor, RenderConstants::TextColor, 1.0f);

    float x = _positions[markIndex];
    glBegin(GL_TRIANGLES);
    glVertex2f(x - 0.3f, 0.0f);
    glVertex2f(x + 0.3f, 0.0f);
    glVertex2f(x, 1.0f);
    glEnd();

    glPopMatrix();
}

EnemyShipMarkRenderer* EnemyShipMarkRendererResolvingFactory::Make(Resolver&)
{
    return new EnemyShipMarkRenderer();
}
