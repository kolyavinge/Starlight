#pragma once

#include <lib/di/ResolvingFactory.h>
#include <core/Camera.h>
#include <core/Race.h>
#include <ui/Screen.h>
#include <vox/common/ShipVox.h>
#include <vox/ui/ScreenVox.h>

class FinishVox : public ScreenVox
{
    Camera& _camera;
    Race& _race;
    ShipVox& _shipVox;

public:
    FinishVox(
        Camera& camera,
        Race& race,
        ShipVox& shipVox);

    void Deactivate() override;
    void Voice(Screen& screen) override;
};

class FinishVoxResolvingFactory : public ResolvingFactory<FinishVox>
{
public:
    FinishVox* Make(Resolver& resolver) override;
};
