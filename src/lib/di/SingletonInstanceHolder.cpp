#include <lib/di/SingletonInstanceHolder.h>

SingletonInstanceHolder::SingletonInstanceHolder(InstanceHolder* instanceHolder)
{
    _instanceHolder = instanceHolder;
    _instance = nullptr;
}

Object* SingletonInstanceHolder::GetInstance(Resolver& resolver)
{
    if (_instance == nullptr)
    {
        _instance = _instanceHolder->GetInstance(resolver);
    }

    return _instance;
}
