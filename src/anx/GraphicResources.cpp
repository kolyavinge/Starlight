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
