#include <lib/String.h>
#include <lib/Environment.h>
#include <anx/AudioResources.h>

String AudioResources::GetSelectMenuItemWavFilePath()
{
    String path(Environment::GetExecutableDirectoryPath());
    String name(L"res\\audio\\select_menu_item.wav\0");
    path.Append(name);

    return path;
}

String AudioResources::GetCountdownWavFilePath()
{
    String path(Environment::GetExecutableDirectoryPath());
    String name(L"res\\audio\\countdown.wav\0");
    path.Append(name);

    return path;
}

String AudioResources::GetLaserWavFilePath()
{
    String path(Environment::GetExecutableDirectoryPath());
    String name(L"res\\audio\\laser.wav\0");
    path.Append(name);

    return path;
}

String AudioResources::GetMetalHitWavFilePath()
{
    String path(Environment::GetExecutableDirectoryPath());
    String name(L"res\\audio\\metal_hit.wav\0");
    path.Append(name);

    return path;
}

String AudioResources::GetExplosionWavFilePath()
{
    String path(Environment::GetExecutableDirectoryPath());
    String name(L"res\\audio\\explosion.wav\0");
    path.Append(name);

    return path;
}

String AudioResources::GetPowerUpPickWavFilePath()
{
    String path(Environment::GetExecutableDirectoryPath());
    String name(L"res\\audio\\powerup_pick.wav\0");
    path.Append(name);

    return path;
}

String AudioResources::GetEngineIdleWavFilePath()
{
    String path(Environment::GetExecutableDirectoryPath());
    String name(L"res\\audio\\engine_idle.wav\0");
    path.Append(name);

    return path;
}

String AudioResources::GetEngineThrottleWavFilePath()
{
    String path(Environment::GetExecutableDirectoryPath());
    String name(L"res\\audio\\engine_throttle.wav\0");
    path.Append(name);

    return path;
}
