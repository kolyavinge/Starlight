#pragma once

#include <lib/Object.h>
#include <calc/SinPeriodValue.h>

class SelectedItemColor : public Object
{
    SinPeriodValue _selectedItemAlpha;

public:
    void SetColorForSelectedItem(bool isSelected);
    void Update();
};
