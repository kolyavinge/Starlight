#include <lib/String.h>
#include <lib/Environment.h>
#include <anx/GraphicResources.h>

String GraphicResources::GetBackgroundTextureFilePath()
{
    String path(Environment::GetExecutableDirectoryPath());
    String name(L"res\\bg1.jpg\0");
    path.Append(name);

    return path;
}

String GraphicResources::GetShipMeshFilePath()
{
    String path(Environment::GetExecutableDirectoryPath());
    String name(L"res\\ship\\Starship.obj\0");
    path.Append(name);

    return path;
}

String GraphicResources::GetStartGameMenuItemFilePath()
{
    String path(Environment::GetExecutableDirectoryPath());
    String name(L"res\\menu\\start_game.png\0");
    path.Append(name);

    return path;
}

String GraphicResources::GetExitMenuItemFilePath()
{
    String path(Environment::GetExecutableDirectoryPath());
    String name(L"res\\menu\\exit.png\0");
    path.Append(name);

    return path;
}

String GraphicResources::GetSelectTrackMenuItemFilePath()
{
    String path(Environment::GetExecutableDirectoryPath());
    String name(L"res\\menu\\select_track.png\0");
    path.Append(name);

    return path;
}

String GraphicResources::GetRaceMenuItemFilePath()
{
    String path(Environment::GetExecutableDirectoryPath());
    String name(L"res\\menu\\race.png\0");
    path.Append(name);

    return path;
}

String GraphicResources::GetBackMenuItemFilePath()
{
    String path(Environment::GetExecutableDirectoryPath());
    String name(L"res\\menu\\back.png\0");
    path.Append(name);

    return path;
}

String GraphicResources::GetPauseItemFilePath()
{
    String path(Environment::GetExecutableDirectoryPath());
    String name(L"res\\menu\\pause.png\0");
    path.Append(name);

    return path;
}

String GraphicResources::GetResumeMenuItemFilePath()
{
    String path(Environment::GetExecutableDirectoryPath());
    String name(L"res\\menu\\resume.png\0");
    path.Append(name);

    return path;
}

String GraphicResources::GetStartMenuMenuItemFilePath()
{
    String path(Environment::GetExecutableDirectoryPath());
    String name(L"res\\menu\\main_menu.png\0");
    path.Append(name);

    return path;
}

String GraphicResources::GetTrackSelectionRectFilePath()
{
    String path(Environment::GetExecutableDirectoryPath());
    String name(L"res\\menu\\track_selection_rect.png\0");
    path.Append(name);

    return path;
}

String GraphicResources::GetAlphabetFilePath()
{
    String path(Environment::GetExecutableDirectoryPath());
    String name(L"res\\alph.png\0");
    path.Append(name);

    return path;
}

String GraphicResources::GetCountdown1ItemFilePath()
{
    String path(Environment::GetExecutableDirectoryPath());
    String name(L"res\\1.png\0");
    path.Append(name);

    return path;
}

String GraphicResources::GetCountdown2ItemFilePath()
{
    String path(Environment::GetExecutableDirectoryPath());
    String name(L"res\\2.png\0");
    path.Append(name);

    return path;
}

String GraphicResources::GetCountdown3ItemFilePath()
{
    String path(Environment::GetExecutableDirectoryPath());
    String name(L"res\\3.png\0");
    path.Append(name);

    return path;
}

String GraphicResources::GetGoItemFilePath()
{
    String path(Environment::GetExecutableDirectoryPath());
    String name(L"res\\go.png\0");
    path.Append(name);

    return path;
}

String GraphicResources::GetFinishItemFilePath()
{
    String path(Environment::GetExecutableDirectoryPath());
    String name(L"res\\finish.png\0");
    path.Append(name);

    return path;
}

String GraphicResources::GetPosition1ItemFilePath()
{
    String path(Environment::GetExecutableDirectoryPath());
    String name(L"res\\1st.png\0");
    path.Append(name);

    return path;
}

String GraphicResources::GetPosition2ItemFilePath()
{
    String path(Environment::GetExecutableDirectoryPath());
    String name(L"res\\2nd.png\0");
    path.Append(name);

    return path;
}

String GraphicResources::GetPosition3ItemFilePath()
{
    String path(Environment::GetExecutableDirectoryPath());
    String name(L"res\\3rd.png\0");
    path.Append(name);

    return path;
}

String GraphicResources::GetPosition4ItemFilePath()
{
    String path(Environment::GetExecutableDirectoryPath());
    String name(L"res\\4th.png\0");
    path.Append(name);

    return path;
}

String GraphicResources::GetExplosionFilePath()
{
    String path(Environment::GetExecutableDirectoryPath());
    String name(L"res\\explosion.png\0");
    path.Append(name);

    return path;
}

String GraphicResources::GetDamageEffectFilePath()
{
    String path(Environment::GetExecutableDirectoryPath());
    String name(L"res\\damage_effect.png\0");
    path.Append(name);

    return path;
}

String GraphicResources::GetDefaultVertexShaderPath()
{
    String path(Environment::GetExecutableDirectoryPath());
    String name(L"res\\shaders\\default.vert\0");
    path.Append(name);

    return path;
}

String GraphicResources::GetDefaultFragmentShaderPath()
{
    String path(Environment::GetExecutableDirectoryPath());
    String name(L"res\\shaders\\default.frag\0");
    path.Append(name);

    return path;
}

String GraphicResources::GetExhaustVertexShaderPath()
{
    String path(Environment::GetExecutableDirectoryPath());
    String name(L"res\\shaders\\exhaust.vert\0");
    path.Append(name);

    return path;
}

String GraphicResources::GetExhaustFragmentShaderPath()
{
    String path(Environment::GetExecutableDirectoryPath());
    String name(L"res\\shaders\\exhaust.frag\0");
    path.Append(name);

    return path;
}

String GraphicResources::GetMeshVertexShaderPath()
{
    String path(Environment::GetExecutableDirectoryPath());
    String name(L"res\\shaders\\mesh.vert\0");
    path.Append(name);

    return path;
}

String GraphicResources::GetMeshFragmentShaderPath()
{
    String path(Environment::GetExecutableDirectoryPath());
    String name(L"res\\shaders\\mesh.frag\0");
    path.Append(name);

    return path;
}

String GraphicResources::GetMainVertexShaderPath()
{
    String path(Environment::GetExecutableDirectoryPath());
    String name(L"res\\shaders\\main.vert\0");
    path.Append(name);

    return path;
}

String GraphicResources::GetMainFragmentShaderPath()
{
    String path(Environment::GetExecutableDirectoryPath());
    String name(L"res\\shaders\\main.frag\0");
    path.Append(name);

    return path;
}

String GraphicResources::GetVertexOnlyVertexShaderPath()
{
    String path(Environment::GetExecutableDirectoryPath());
    String name(L"res\\shaders\\vertexOnly.vert\0");
    path.Append(name);

    return path;
}

String GraphicResources::GetPowerUpHealthFilePath()
{
    String path(Environment::GetExecutableDirectoryPath());
    String name(L"res\\powerup_health.png\0");
    path.Append(name);

    return path;
}

String GraphicResources::GetPowerUpMachinegunFilePath()
{
    String path(Environment::GetExecutableDirectoryPath());
    String name(L"res\\powerup_machinegun.png\0");
    path.Append(name);

    return path;
}

String GraphicResources::GetPowerUpNitroFilePath()
{
    String path(Environment::GetExecutableDirectoryPath());
    String name(L"res\\powerup_nitro.png\0");
    path.Append(name);

    return path;
}

String GraphicResources::GetTrackGround1TextureFilePath()
{
    String path(Environment::GetExecutableDirectoryPath());
    String name(L"res\\track_ground1.jpg\0");
    path.Append(name);

    return path;
}

String GraphicResources::GetTrackEdgeTextureFilePath()
{
    String path(Environment::GetExecutableDirectoryPath());
    String name(L"res\\track_edge.jpg\0");
    path.Append(name);

    return path;
}

String GraphicResources::GetExhaustFilesPath()
{
    String path(Environment::GetExecutableDirectoryPath());
    String name(L"res\\exhaust\0");
    path.Append(name);

    return path;
}
