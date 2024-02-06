#pragma once

#include <ui/ScreenKind.h>

class IScreenNavigator
{
public:
    virtual void NavigateTo(ScreenKind kind) = 0;
};
