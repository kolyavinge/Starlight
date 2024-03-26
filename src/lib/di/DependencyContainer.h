#pragma once

#include <lib/Object.h>
#include <lib/di/InstanceCollection.h>
#include <lib/di/Resolver.h>
#include <lib/di/Binder.h>
#include <lib/di/InjectModule.h>

class DependencyContainer : public Object
{
    InstanceCollection _instances;
    Resolver _resolver;
    Binder _binder;

public:
    DependencyContainer() :
        _resolver(_instances),
        _binder(_instances)
    {
    }

    template<class TInstance>
    TInstance& Resolve()
    {
        return _resolver.Resolve<TInstance>();
    }

    template<class TInstance, class TResolvingFactory>
    void BindSingletonByFactory()
    {
        return _binder.BindSingletonByFactory<TInstance, TResolvingFactory>();
    }

    void InitFromModule(InjectModule& module)
    {
        module.Init(_binder);
    }
};
