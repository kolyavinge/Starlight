#pragma once

#include <lib/Object.h>
#include <lib/Exceptions.h>
#include <lib/di/InstanceCollection.h>
#include <lib/di/ResolvingFactoryInstanceHolder.h>
#include <lib/di/FunctionInstanceHolder.h>
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
    void BindByFactory()
    {
        if (!_instances.ContainsType(typeid(TInstance)))
        {
            _instances.Add(typeid(TInstance), new ResolvingFactoryInstanceHolder<TResolvingFactory>());
        }
        else
        {
            throw BindException();
        }
    }

    template<class TInstance, class TResolvingFactory>
    void BindSingletonByFactory()
    {
        if (!_instances.ContainsType(typeid(TInstance)))
        {
            _instances.Add(typeid(TInstance), new SingletonInstanceHolder(new ResolvingFactoryInstanceHolder<TResolvingFactory>()));
        }
        else
        {
            throw BindException();
        }
    }

    template<class TInstance>
    void BindByFunction(ResolvingFunction<TInstance> func)
    {
        if (!_instances.ContainsType(typeid(TInstance)))
        {
            _instances.Add(typeid(TInstance), new FunctionInstanceHolder<TInstance>(func));
        }
        else
        {
            throw BindException();
        }
    }

    template<class TInstance>
    void BindSingletonByFunction(ResolvingFunction<TInstance> func)
    {
        if (!_instances.ContainsType(typeid(TInstance)))
        {
            _instances.Add(typeid(TInstance), new SingletonInstanceHolder(new FunctionInstanceHolder<TInstance>(func)));
        }
        else
        {
            throw BindException();
        }
    }
};
