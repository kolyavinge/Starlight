#pragma once

#include <lib/Object.h>
#include <lib/di/Resolver.h>
#include <lib/di/InstanceHolder.h>

class SingletonInstanceHolder : public InstanceHolder
{
    InstanceHolder* _instanceHolder;
    Object* _instance;

public:
    SingletonInstanceHolder(InstanceHolder* instanceHolder);

    Object* GetInstance(Resolver& resolver) override;
};
