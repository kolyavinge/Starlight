#pragma once

#include <lib/di/ResolvingFactory.h>
#include <ui/Screen.h>
#include <vox/ui/ScreenVox.h>

class FinishVox : public ScreenVox
{
public:
    void Voice(Screen& screen) override;
};

class FinishVoxResolvingFactory : public ResolvingFactory<FinishVox>
{
public:
    FinishVox* Make(Resolver& resolver) override;
};
