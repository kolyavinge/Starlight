#pragma once

#include <lib/Object.h>
#include <lib/di/Resolver.h>

template<class TInstance>
class ResolvingFactory : public Object
{
public:
    virtual TInstance* Make(Resolver& resolver) = 0;
};
