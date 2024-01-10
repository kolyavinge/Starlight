#include <lib/String.h>
#include <lib/Environment.h>
#include <gl/Textures.h>

String Textures::GetBackgroundTextureFilePath()
{
    String path(Environment::GetExecutableDirectoryPath());
    String name(L"res\\bg1.jpg\0");
    path.Append(name);

    return path;
}
