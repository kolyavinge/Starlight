#pragma once

#include <lib/Object.h>
#include <lib/di/Binder.h>

class InjectModule : public Object
{
public:
    virtual void Init(Binder& binder) = 0;
};
