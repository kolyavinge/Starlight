#include <lib/Math.h>
#include <calc/Geometry.h>
#include <calc/SinPeriodValue.h>

SinPeriodValue::SinPeriodValue()
{
    _radians = 0.0f;
}

float SinPeriodValue::GetRadians()
{
    return _radians;
}

void SinPeriodValue::SetRadians(float value)
{
    _radians = value;
}

void SinPeriodValue::Update(float step)
{
    _radians = Geometry::NormalizeRadians(_radians + step);
}

float SinPeriodValue::GetValue()
{
    return Math::Sin(_radians);
}

float SinPeriodValue::GetAbsValue()
{
    return Math::Abs(Math::Sin(_radians));
}
