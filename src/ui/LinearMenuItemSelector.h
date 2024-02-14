#pragma once

#include <windows.h>
#include <lib/List.h>
#include <lib/CycledListIterator.h>
#include <input/InputDevices.h>
#include <ui/MenuItemSelector.h>

enum class LinearMenuItemSelectorOrientation
{
    Vertical,
    Horizontal
};

template<class TMenuItem>
class LinearMenuItemSelector : public MenuItemSelector<TMenuItem>
{
    LinearMenuItemSelectorOrientation _orientation;
    List<TMenuItem> _items;
    CycledListIterator<TMenuItem> _iter;

public:
    LinearMenuItemSelector(LinearMenuItemSelectorOrientation orientation) :
        _iter(_items)
    {
        _orientation = orientation;
    }

    void AddItem(TMenuItem item)
    {
        _items.Add(item);
    }

    TMenuItem& GetSelectedItem() override
    {
        return _iter.GetCurrentItem();
    }

    void Reset() override
    {
        _iter.Reset();
    }

    bool ProcessSelection(InputDevices& inputDevices) override
    {
        if (_orientation == LinearMenuItemSelectorOrientation::Vertical)
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
