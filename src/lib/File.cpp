#include <windows.h>
#include <lib/File.h>

bool File::Exists(const wchar_t* filePath)
{
    WIN32_FIND_DATA findFileData;
    HANDLE handle = FindFirstFile(filePath, &findFileData);
    bool found = handle != INVALID_HANDLE_VALUE;
    if (found)
    {
        FindClose(handle);
    }

    return found;
}

void File::ErrorIfFileNotFound(const wchar_t* filePath)
{
    if (!Exists(filePath))
    {
        throw new FileNotFoundException();
    }
}
