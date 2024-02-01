#include <lib/String.h>
#include <lib/Environment.h>
#include <core/Resources.h>

String Resources::GetBackgroundTextureFilePath()
{
    String path(Environment::GetExecutableDirectoryPath());
    String name(L"res\\bg1.jpg\0");
    path.Append(name);

    return path;
}

String Resources::GetShipMeshFilePath()
{
    String path(Environment::GetExecutableDirectoryPath());
    String name(L"res\\ship\\Starship.obj\0");
    path.Append(name);

    return path;
}

String Resources::GetStartGameMenuItemFilePath()
{
    String path(Environment::GetExecutableDirectoryPath());
    String name(L"res\\menu\\start_game.png\0");
    path.Append(name);

    return path;
}

String Resources::GetExitMenuItemFilePath()
{
    String path(Environment::GetExecutableDirectoryPath());
    String name(L"res\\menu\\exit.png\0");
    path.Append(name);

    return path;
}

String Resources::GetPauseItemFilePath()
{
    String path(Environment::GetExecutableDirectoryPath());
    String name(L"res\\menu\\pause.png\0");
    path.Append(name);

    return path;
}

String Resources::GetResumeMenuItemFilePath()
{
    String path(Environment::GetExecutableDirectoryPath());
    String name(L"res\\menu\\resume.png\0");
    path.Append(name);

    return path;
}

String Resources::GetStartMenuMenuItemFilePath()
{
    String path(Environment::GetExecutableDirectoryPath());
    String name(L"res\\menu\\main_menu.png\0");
    path.Append(name);

    return path;
}

String Resources::GetSelectMenuItemWavFilePath()
{
    String path(Environment::GetExecutableDirectoryPath());
    String name(L"res\\audio\\select_menu_item.wav\0");
    path.Append(name);

    return path;
}
