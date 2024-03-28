#pragma once

#include <lib/di/InjectModule.h>
#include <lib/di/Binder.h>

class VoxInjectModule : public InjectModule
{
public:
    void Init(Binder& binder) override;
};
