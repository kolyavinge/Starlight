#include <windows.h>
#include <lib/Exceptions.h>
#include <lib/Directory.h>

void Directory::GetFiles(String directory, List<String>& files)
{
    WIN32_FIND_DATA findData;
    String searchPath(directory);
    searchPath.Append(L"\\*");
    HANDLE fileHandle = FindFirstFile(searchPath.GetWCharBuf(), &findData);
    if (fileHandle == INVALID_HANDLE_VALUE)
    {
        throw ArgumentException();
    }
    String fileName;
    while (FindNextFile(fileHandle, &findData))
    {
        if (!(findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
        {
            fileName.Clear();
            fileName.Append(directory).Append(L"\\").Append(findData.cFileName);
            files.Add(fileName);
        }
    }
    FindClose(fileHandle);
}
