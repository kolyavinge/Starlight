#pragma once

#include <windows.h>
#include <lib/Object.h>
#include <lib/Array.h>
#include <lib/CycledArrayIterator.h>
#include <input/InputDevices.h>

template<class TMenuItem, int Count>
class MenuItemSelector : public Object
{
    Array<TMenuItem, Count> _items;
    CycledArrayIterator<TMenuItem, Count> _iter;

public:
    MenuItemSelector() :
        _iter(_items)
    {
    }

    void Init(Array<TMenuItem, Count>& items)
    {
        for (int i = 0; i < Count; i++)
        {
            _items[i] = items[i];
        }
    }

    TMenuItem& GetSelectedItem()
    {
        return _iter.GetCurrentItem();
    }

    bool ProcessSelection(InputDevices& inputDevices)
    {
        if (inputDevices.Keyboard.IsPressed(VK_UP) ||
            inputDevices.Keyboard.IsPressed('w') ||
            inputDevices.Joystick.IsUpPressed())
        {
            inputDevices.Keyboard.Release(VK_UP);
            inputDevices.Keyboard.Release('w');
            _iter.Prev();
            return true;
        }

        if (inputDevices.Keyboard.IsPressed(VK_DOWN) ||
            inputDevices.Keyboard.IsPressed('s') ||
            inputDevices.Joystick.IsDownPressed())
        {
            inputDevices.Keyboard.Release(VK_DOWN);
            inputDevices.Keyboard.Release('s');
            _iter.Next();
            return true;
        }

        return false;
    }
};
