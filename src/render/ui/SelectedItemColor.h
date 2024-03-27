#pragma once

#include <lib/Object.h>
#include <lib/di/ResolvingFactory.h>
#include <calc/SinPeriodValue.h>

class SelectedItemColor : public Object
{
    SinPeriodValue _selectedItemAlpha;

public:
    void SetColorForSelectedItem(bool isSelected);
    void Update();
};

class SelectedItemColorResolvingFactory : public ResolvingFactory<SelectedItemColor>
{
public:
    SelectedItemColor* Make(Resolver& resolver) override;
};
