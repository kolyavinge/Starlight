#pragma once

class Math
{
public:
    static const float Pi;
    static const float PiHalf;

    static float Abs(float x);
    static float Sqrt(float x);
    static float Sin(float radians);
    static float Cos(float radians);
    static float Tan(float radians);
    static float ArcSin(float x);
    static float ArcCos(float x);
    static float ArcTan(float x);
};
