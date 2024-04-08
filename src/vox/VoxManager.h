#pragma once

#include <lib/Object.h>
#include <lib/di/ResolvingFactory.h>
#include <ui/Screen.h>
#include <vox/ScreenVox.h>
#include <vox/ScreenVoxCollection.h>

class VoxManager : public Object
{
    ScreenVoxCollection& _voxCollection;

public:
    VoxManager(ScreenVoxCollection& voxCollection);

    void Init();
    ScreenVox& GetScreenVox(Screen& screen);
};

class VoxManagerResolvingFactory : public ResolvingFactory<VoxManager>
{
public:
    VoxManager* Make(Resolver& resolver) override;
};
