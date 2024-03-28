#pragma once

#include <lib/Object.h>
#include <lib/String.h>
#include <lib/di/Resolver.h>
#include <lib/di/InstanceHolder.h>

template<class TResolvingFactory>
class SingletonInstanceHolder : public InstanceHolder
{
    Object* _instance;

public:
    SingletonInstanceHolder()
    {
        _instance = nullptr;
    }

    Object* GetInstance(Resolver& resolver) override
    {
        if (_instance == nullptr)
        {
            InstancesCount = 1;
            TResolvingFactory factory{};
            _instance = factory.Make(resolver);
        }

        return _instance;
    }

    String GetInstanceName() override
    {
        return String(typeid(TResolvingFactory).name());
    }
};
