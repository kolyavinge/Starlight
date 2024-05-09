#include <windows.h>
#include <gdiplus.h>
#include <lib/File.h>
#include <gl/ImageFile.h>

void ImageFile::GetSize(const wchar_t* fileName, int* width, int* height)
{
    using namespace Gdiplus;

    File::ErrorIfFileNotFound(fileName);
    ULONG_PTR gdiplusToken;
    GdiplusStartupInput gdiplusStartupInput;
    GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
    Bitmap* bitmap = Bitmap::FromFile(fileName);

    *width = (int)bitmap->GetWidth();
    *height = (int)bitmap->GetHeight();

    delete bitmap;
}
