#pragma once

#include <lib/Object.h>

class Resolver;

class InstanceHolder : public Object
{
public:
    virtual Object* GetInstance(Resolver& resolver) = 0;
};
