#pragma once

#include <windows.h>
#include <gdiplus.h>
#include <lib/Object.h>

struct PixelData
{
    unsigned char R;
    unsigned char G;
    unsigned char B;
    unsigned char A;
};

class ImageFile : public Object
{
    Gdiplus::Bitmap* _bitmap;

public:
    ImageFile(const wchar_t* fileName);
    ~ImageFile();

    int GetWidth();
    int GetHeight();
    void GetPixelData(int x, int y, PixelData& result);
};
