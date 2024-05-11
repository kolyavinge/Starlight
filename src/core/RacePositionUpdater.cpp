#include <core/RacePositionUpdater.h>

void RacePositionUpdater::Update(Collection<Ship*>& allShipsSortedByPositions)
{
    allShipsSortedByPositions.Sort(_comparator);

    for (int i = 0; i < allShipsSortedByPositions.GetCount(); i++)
    {
        allShipsSortedByPositions[i]->RacePosition = i + 1;
    }
}

RacePositionUpdater* RacePositionUpdaterResolvingFactory::Make(Resolver&)
{
    return new RacePositionUpdater();
}
