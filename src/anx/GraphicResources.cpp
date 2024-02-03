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
