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
        throw FileNotFoundException();
    }
}

long long File::GetFileSizeBytes(const wchar_t* filePath)
{
    ErrorIfFileNotFound(filePath);
    WIN32_FILE_ATTRIBUTE_DATA fad;
    GetFileAttributesEx(filePath, GetFileExInfoStandard, &fad);
    LARGE_INTEGER size;
    size.HighPart = fad.nFileSizeHigh;
    size.LowPart = fad.nFileSizeLow;

    return size.QuadPart;
}

int File::ReadAllBytes(const wchar_t* filePath, int bufferSize, void* buffer)
{
    ErrorIfFileNotFound(filePath);
    DWORD readedBytes = 0;
    HANDLE hFile = CreateFile(filePath, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
    bool readResult = ReadFile(hFile, buffer, bufferSize, &readedBytes, NULL);
    CloseHandle(hFile);
    if (!readResult) throw ReadFileException();

    return readedBytes;
}
