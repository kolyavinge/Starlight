#include <lib/Path.h>

String Path::GetDirectoryPath(String path)
{
    int slash = path.LastIndexOf(L'\\');
    if (slash == -1) throw InvalidPathException();
    String result = path.Substring(0, slash);

    return result;
}

String Path::GetFileNameWithExtension(String path)
{
    int slash = path.LastIndexOf(L'\\');
    if (slash == -1) throw InvalidPathException();
    String result = path.Substring(slash + 1, path.GetLength() - slash - 1);

    return result;
}

String Path::GetFileNameWithoutExtension(String path)
{
    int slash = path.LastIndexOf(L'\\');
    if (slash == -1) throw InvalidPathException();
    int dot = path.LastIndexOf(L'.');
    if (dot == -1) throw InvalidPathException();
    String result = path.Substring(slash + 1, dot - slash - 1);

    return result;
}

String Path::GetFileExtension(String path)
{
    int dot = path.LastIndexOf(L'.');
    if (dot == -1) throw InvalidPathException();
    String result = path.Substring(dot + 1, path.GetLength() - dot - 1);

    return result;
}
