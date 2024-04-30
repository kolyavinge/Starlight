#include <core/RacePositionUpdater.h>

void RacePositionUpdater::Update(Collection<Ship*>& allShips)
{
    allShips.Sort(_comparator);

    for (int i = 0; i < allShips.GetCount(); i++)
    {
        allShips[i]->RacePosition = i + 1;
    }
}

RacePositionUpdater* RacePositionUpdaterResolvingFactory::Make(Resolver&)
{
    return new RacePositionUpdater();
}
