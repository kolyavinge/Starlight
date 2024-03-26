#pragma once

#include <lib/Object.h>
#include <lib/Exceptions.h>
#include <lib/di/InstanceCollection.h>
#include <lib/di/SingletonInstanceHolder.h>

class BindException : public Exception { };

class Binder : public Object
{
    InstanceCollection& _instances;

public:
    Binder(InstanceCollection& instances) :
        _instances(instances)
    {
    }

    template<class TInstance, class TResolvingFactory>
    void BindSingletonByFactory()
    {
        if (!_instances.ContainsType(typeid(TInstance)))
        {
            _instances.Add(typeid(TInstance), new SingletonInstanceHolder<TResolvingFactory>());
        }
        else
        {
            throw BindException();
        }
    }
};
