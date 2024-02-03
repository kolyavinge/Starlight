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
