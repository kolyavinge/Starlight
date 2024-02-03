#pragma once

#include <windows.h>
#include <lib/Object.h>
#include <lib/Array.h>
#include <lib/CycledArrayIterator.h>
#include <input/InputDevices.h>

enum class MenuItemSelectorOrientation
{
    Vertical,
    Horizontal
};

template<class TMenuItem, int Count>
class MenuItemSelector : public Object
{
    MenuItemSelectorOrientation _orientation;
    Array<TMenuItem, Count> _items;
    CycledArrayIterator<TMenuItem, Count> _iter;

public:
    MenuItemSelector(MenuItemSelectorOrientation orientation) :
        _iter(_items)
    {
        _orientation = orientation;
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
        if (_orientation == MenuItemSelectorOrientation::Vertical)
        {
            return ProcessSelectionVertical(inputDevices);
        }
        else
        {
            return ProcessSelectionHorizontal(inputDevices);
        }
    }

private:
    bool ProcessSelectionVertical(InputDevices& inputDevices)
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

    bool ProcessSelectionHorizontal(InputDevices& inputDevices)
    {
        if (inputDevices.Keyboard.IsPressed(VK_LEFT) ||
            inputDevices.Keyboard.IsPressed('A') ||
            inputDevices.Joystick.IsLeftPressed())
        {
            _iter.Prev();
            return true;
        }

        if (inputDevices.Keyboard.IsPressed(VK_RIGHT) ||
            inputDevices.Keyboard.IsPressed('D') ||
            inputDevices.Joystick.IsRightPressed())
        {
            _iter.Next();
            return true;
        }

        return false;
    }
};
