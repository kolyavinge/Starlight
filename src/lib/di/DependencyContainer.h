#pragma once

#include <lib/Object.h>
#include <lib/String.h>
#include <lib/List.h>
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

    void InitFromModule(InjectModule& module)
    {
        module.Init(_binder);
    }

    String GetUnusedInstancesAsString()
    {
        List<String> unusedInstances;
        _instances.GetUnusedInstances(unusedInstances);
        String result;
        for (int i = 0; i < unusedInstances.GetCount(); i++)
        {
            result.Append(unusedInstances[i]);
            result.Append(L'\n');
        }

        return result;
    }
};
