#pragma once

#include <lib/Object.h>

class Resolver;

class InstanceHolder : public Object
{
public:
    int InstancesCount;

    InstanceHolder();

    virtual Object* GetInstance(Resolver& resolver) = 0;
};
