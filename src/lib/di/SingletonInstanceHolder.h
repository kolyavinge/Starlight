#pragma once

#include <lib/Object.h>
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
            TResolvingFactory factory{};
            _instance = factory.Make(resolver);
        }

        return _instance;
    }
};
