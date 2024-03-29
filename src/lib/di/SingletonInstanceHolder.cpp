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
        InstancesCount = 1;
        _instance = _instanceHolder->GetInstance(resolver);
    }

    return _instance;
}

String SingletonInstanceHolder::GetInstanceName()
{
    return _instanceHolder->GetInstanceName();
}
