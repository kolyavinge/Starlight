#include <model/NitroCollection.h>

NitroCollection::NitroCollection()
{
    Init();
}

void NitroCollection::Init()
{
    _count = 0;
}

void NitroCollection::AddOne()
{
    if (!IsFull())
    {
        _count++;
    }
}

bool NitroCollection::IsFull()
{
    return _count == MaxCount;
}

int NitroCollection::GetCount()
{
    return _count;
}
