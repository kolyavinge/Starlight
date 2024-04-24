#include <model/ShipCompletedRaceDistanceComparator.h>

int ShipCompletedRaceDistanceComparator::Compare(Ship* a, Ship* b)
{
    // descending
    if (a->CompletedRaceDistance < b->CompletedRaceDistance)
    {
        return 1;
    }
    else if (a->CompletedRaceDistance > b->CompletedRaceDistance)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}
