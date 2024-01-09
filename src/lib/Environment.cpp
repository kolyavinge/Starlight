#include <windows.h>
#include <lib/Environment.h>

String Environment::GetCurrentDirectoryPath()
{
    wchar_t buf[MAX_PATH];
    GetCurrentDirectory(MAX_PATH, buf);

    return String(buf);
}

String Environment::GetExecutableFilePath()
{
    wchar_t buf[MAX_PATH];
    GetModuleFileName(NULL, buf, MAX_PATH);

    return String(buf);
}

String Environment::GetExecutableDirectoryPath()
{
    wchar_t buf[MAX_PATH];
    int len = GetModuleFileName(NULL, buf, MAX_PATH);
    for (int i = len - 1; i >= 0 && buf[i] != '\\'; i--)
    {
        buf[i] = '\0';
    }

    return String(buf);
}
