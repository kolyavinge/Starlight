#pragma once

#include <lib/Object.h>
#include <lib/Exceptions.h>
#include <lib/di/InstanceCollection.h>

class ResolveException : public Exception { };

class Resolver : public Object
{
    InstanceCollection& _instances;

public:
    Resolver(InstanceCollection& instances) :
        _instances(instances)
    {
    }

    template<class TInstance>
    TInstance& Resolve()
    {
        if (_instances.ContainsType(typeid(TInstance)))
        {
            TInstance* instance = (TInstance*)_instances[typeid(TInstance)]->GetInstance(*this);
            return (TInstance&)*instance;
        }
        else
        {
            throw ResolveException();
        }
    }
};
