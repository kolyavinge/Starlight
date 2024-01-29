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
