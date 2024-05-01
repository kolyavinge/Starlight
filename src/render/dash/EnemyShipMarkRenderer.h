#pragma once

#include <lib/Object.h>
#include <lib/Collection.h>
#include <lib/List.h>
#include <lib/di/ResolvingFactory.h>
#include <model/Ship.h>
#include <model/Track.h>

class EnemyShipMarkRenderer : public Object
{
    List<Vector3> _enemyDistance;

public:
    void Render(Ship& player, Collection<Ship*>& allShips, Track& track);

private:
    int GetPlayerIndex(Ship& player, Collection<Ship*>& allShips);
    void CalculateEmenyDisatance(int playerIndex, Ship& player, Collection<Ship*>& allShips);
    void RenderMarks(Ship& player, Track& track);
    void RenderMark(int markIndex, Ship& player, Track& track);
};

class EnemyShipMarkRendererResolvingFactory : public ResolvingFactory<EnemyShipMarkRenderer>
{
public:
    EnemyShipMarkRenderer* Make(Resolver& resolver);
};
