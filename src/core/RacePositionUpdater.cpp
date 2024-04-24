#include <core/RacePositionUpdater.h>

void RacePositionUpdater::Init(List<Ship*>& allShips)
{
    _allShips = allShips;
}

void RacePositionUpdater::Update()
{
    _allShips.Sort(_comparator);

    for (int i = 0; i < _allShips.GetCount(); i++)
    {
        _allShips[i]->RacePosition = i + 1;
    }
}

RacePositionUpdater* RacePositionUpdaterResolvingFactory::Make(Resolver&)
{
    return new RacePositionUpdater();
}
