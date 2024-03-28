#pragma once

#include <lib/Object.h>
#include <lib/String.h>
#include <lib/Assert.h>
#include <lib/di/Resolver.h>
#include <lib/di/InstanceHolder.h>

template<class TResolvingFactory>
class ResolvingFactoryInstanceHolder : public InstanceHolder
{
public:
    Object* GetInstance(Resolver& resolver) override
    {
        InstancesCount++;
        TResolvingFactory factory{};
        Object* instance = (Object*)factory.Make(resolver);
        Assert::False(instance == nullptr);

        return instance;
    }

    String GetInstanceName() override
    {
        return String(typeid(TResolvingFactory).name());
    }
};
