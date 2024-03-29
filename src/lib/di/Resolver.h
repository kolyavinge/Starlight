#pragma once

#include <typeinfo>
#include <lib/Object.h>
#include <lib/Exceptions.h>
#include <lib/List.h>
#include <lib/Dictionary.h>
#include <lib/di/InstanceCollection.h>

class ResolveException : public Exception { };

class Resolver : public Object
{
    InstanceCollection& _instances;
    Dictionary<unsigned int, const type_info*> _resolved;

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
            AddResolvedInstance(typeid(TInstance));
            TInstance* instance = (TInstance*)_instances[typeid(TInstance)]->GetInstance(*this);
            return (TInstance&)*instance;
        }
        else
        {
            throw ResolveException();
        }
    }

    void GetResolvedTypeHashKeys(List<unsigned int>& typeHashKeys)
    {
        _resolved.GetAllKeys(typeHashKeys);
    }

private:
    void AddResolvedInstance(const type_info& type)
    {
        unsigned int key = _instances.GetTypeHashKey(type);
        if (!_resolved.ContainsKey(key))
        {
            _resolved.Add(key, &type);
        }
    }
};
