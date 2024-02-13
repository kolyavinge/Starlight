#pragma once

#include <lib/Object.h>
#include <input/InputDevices.h>

template<class TMenuItem>
class MenuItemSelector : public Object
{
public:
    virtual TMenuItem& GetSelectedItem() = 0;
    virtual void Reset() = 0;
    virtual bool ProcessSelection(InputDevices& inputDevices) = 0;
};
