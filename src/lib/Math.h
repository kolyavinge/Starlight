#pragma once

class Math
{
public:
    inline static const float Pi = 3.14159265359f;
    inline static const float PiHalf = Pi / 2.0f;
    inline static const float PiDouble = 2.0f * Pi;

    static float Min(float a, float b);
    static float Max(float a, float b);
    static int Abs(int x);
    static float Abs(float x);
    static float Sqrt(float x);
    static float Sin(float radians);
    static float Cos(float radians);
    static float Tan(float radians);
    static float ArcSin(float x);
    static float ArcCos(float x);
    static float ArcTan(float x);
    static float LogE(float x);
    static float Round(float x, float precision);
};
