#pragma once

#include <lib/Object.h>
#include <lib/String.h>

class Resolver;

class InstanceHolder : public Object
{
public:
    int InstancesCount;

    InstanceHolder();

    virtual Object* GetInstance(Resolver& resolver) = 0;
    virtual String GetInstanceName() = 0;
};
