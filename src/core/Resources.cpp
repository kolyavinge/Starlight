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