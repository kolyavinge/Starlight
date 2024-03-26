#pragma once

#include <lib/Object.h>
#include <lib/di/Resolver.h>
#include <lib/di/InstanceHolder.h>

template<class TResolvingFactory>
class DefaultInstanceHolder : public InstanceHolder
{
public:
    Object* GetInstance(Resolver& resolver) override
    {
        InstancesCount++;
        TResolvingFactory factory{};

        return factory.Make(resolver);
    }
};
