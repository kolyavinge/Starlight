#pragma once

class Math
{
public:
    static const float Pi;
    static const float PiHalf;
    static const float PiDouble;

    static float Min(float a, float b);
    static float Max(float a, float b);
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
