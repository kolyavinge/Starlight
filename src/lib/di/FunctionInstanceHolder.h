#pragma once

#include <lib/Object.h>
#include <lib/String.h>
#include <lib/Assert.h>
#include <lib/di/Resolver.h>
#include <lib/di/InstanceHolder.h>

template<class TInstance>
using ResolvingFunction = TInstance * (*)(Resolver&);

template<class TInstance>
class FunctionInstanceHolder : public InstanceHolder
{
    ResolvingFunction<TInstance> _func;

public:
    FunctionInstanceHolder(ResolvingFunction<TInstance> func)
    {
        _func = func;
    }

    Object* GetInstance(Resolver& resolver) override
    {
        InstancesCount++;
        Object* instance = (Object*)_func(resolver);
        Assert::False(instance == nullptr);

        return instance;
    }

    String GetInstanceName() override
    {
        return String(typeid(TInstance).name());
    }
};
