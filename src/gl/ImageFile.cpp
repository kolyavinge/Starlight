#include <windows.h>
#include <gl/ImageFile.h>

using namespace Gdiplus;

ImageFile::ImageFile(const wchar_t* fileName)
{
    ULONG_PTR gdiplusToken;
    GdiplusStartupInput gdiplusStartupInput;
    GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
    _bitmap = Bitmap::FromFile(fileName);
}

ImageFile::~ImageFile()
{
    delete _bitmap;
    _bitmap = nullptr;
}

unsigned int ImageFile::GetWidth()
{
    return _bitmap->GetWidth();
}

unsigned int ImageFile::GetHeight()
{
    return _bitmap->GetHeight();
}

void ImageFile::GetPixelData(int x, int y, PixelData& result)
{
    Color color;
    _bitmap->GetPixel(x, y, &color);
    result.R = color.GetR();
    result.G = color.GetG();
    result.B = color.GetB();
    result.A = color.GetA();
}
