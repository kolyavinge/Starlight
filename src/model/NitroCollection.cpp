#include <model/NitroCollection.h>

NitroCollection::NitroCollection()
{
    Init();
}

void NitroCollection::Init()
{
    _count = 0;
    _iterations = 0;
    State = NitroState::Innactive;
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

void NitroCollection::ActivateOne()
{
    State = NitroState::Activated;
    _count--;
    _iterations = _maxIterations;
}

void NitroCollection::Update()
{
    if (State == NitroState::Activated)
    {
        _iterations--;
        if (_iterations == 0)
        {
            State = NitroState::Deactivated;
            _iterations = _maxIterations;
        }
    }
    else if (State == NitroState::Deactivated)
    {
        _iterations--;
        if (_iterations == 0)
        {
            State = NitroState::Innactive;
        }
    }
}
