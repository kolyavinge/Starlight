#pragma once

class Numeric
{
public:
    static bool FloatEquals(float a, float b, float eps = 1e-7f);
    static bool Between(int x, int left, int right);
};
