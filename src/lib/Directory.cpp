#include <windows.h>
#include <lib/Exceptions.h>
#include <lib/Directory.h>

void Directory::GetFiles(String directory, List<String>& files)
{
    WIN32_FIND_DATA findData;
    HANDLE fileHandle = FindFirstFile(directory.GetWCharBuf(), &findData);
    if (fileHandle == INVALID_HANDLE_VALUE)
    {
        throw ArgumentException();
    }
    while (FindNextFile(fileHandle, &findData))
    {
        if (!(findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
        {
            files.Add(String(findData.cFileName));
        }
    }
    FindClose(fileHandle);
}
