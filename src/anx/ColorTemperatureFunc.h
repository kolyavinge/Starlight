#pragma once

#include <lib/Object.h>
#include <lib/Array.h>

class NormalizedRGB : public Object
{
public:
    float R;
    float G;
    float B;

    NormalizedRGB();
    NormalizedRGB(float r, float g, float b);
};

// ��������� ����������� ����� � ��������� � RGB
// �������� �� 1000K �� 40 000K � ����� 100
class ColorTemperatureFunc : public Object
{
    inline static const int ColorsCount = 391;
    inline static const float ColorsMaxIndexFloat = (float)(ColorsCount - 1);

    Array<NormalizedRGB, ColorsCount> _colors;

public:
    ColorTemperatureFunc();

    // normalizedValue - ��������������� �������� �����������
    // 0.0f - 1000K, 1.0f - 40 000K
    NormalizedRGB GetColor(float normalizedValue);
};
