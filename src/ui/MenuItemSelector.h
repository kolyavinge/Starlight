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

    void Reset()
    {
        _iter.Reset();
    }

    bool ProcessSelection(InputDevices& inputDevices)
    {
        if (inputDevices.Keyboard.IsPressed(VK_UP) ||
            inputDevices.Keyboard.IsPressed('W') ||
            inputDevices.Joystick.IsUpPressed())
        {
            _iter.Prev();
            return true;
        }

        if (inputDevices.Keyboard.IsPressed(VK_DOWN) ||
            inputDevices.Keyboard.IsPressed('S') ||
            inputDevices.Joystick.IsDownPressed())
        {
            _iter.Next();
            return true;
        }

        return false;
    }
};
