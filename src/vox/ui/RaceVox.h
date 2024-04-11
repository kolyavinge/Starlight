#pragma once

#include <lib/di/ResolvingFactory.h>
#include <core/Race.h>
#include <ui/Screen.h>
#include <vox/common/ShipVox.h>
#include <vox/ui/ScreenVox.h>

class RaceVox : public ScreenVox
{
    ShipVox& _shipVox;
    Race& _race;

public:
    RaceVox(
        ShipVox& shipVox,
        Race& race);

    void Deactivate() override;
    void Voice(Screen& screen) override;
};

class RaceVoxResolvingFactory : public ResolvingFactory<RaceVox>
{
public:
    RaceVox* Make(Resolver& resolver) override;
};
