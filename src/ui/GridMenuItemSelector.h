#pragma once

#include <windows.h>
#include <lib/Array.h>
#include <lib/Memory.h>
#include <input/InputDevices.h>
#include <ui/MenuItemSelector.h>

template<class TMenuItem, int Rows, int Cols>
class GridMenuItemSelector : public MenuItemSelector<TMenuItem>
{
    TMenuItem _items[Rows][Cols];
    int _selectedRow, _selectedCol;

public:
    GridMenuItemSelector()
    {
        Memory::Zero<TMenuItem>(&_items[0][0], Rows * Cols);
        _selectedRow = 0;
        _selectedCol = 0;
    }

    template<int Count>
    void Init(Array<TMenuItem, Count>& items)
    {
        int i = 0;
        for (int row = 0; row < Rows; row++)
        {
            for (int col = 0; col < Cols; col++)
            {
                _items[row][col] = items[i++];
            }
        }
    }

    TMenuItem& GetSelectedItem() override
    {
        return _items[_selectedRow][_selectedCol];
    }

    void Reset() override
    {
        _selectedRow = 0;
        _selectedCol = 0;
    }

    bool ProcessSelection(InputDevices& inputDevices) override
    {
        if (inputDevices.Keyboard.IsPressed(VK_UP) ||
            inputDevices.Keyboard.IsPressed('W') ||
            inputDevices.Joystick.IsUpPressed())
        {
            _selectedRow--;
            NormalizeSelected();
            return true;
        }

        if (inputDevices.Keyboard.IsPressed(VK_DOWN) ||
            inputDevices.Keyboard.IsPressed('S') ||
            inputDevices.Joystick.IsDownPressed())
        {
            _selectedRow++;
            NormalizeSelected();
            return true;
        }

        if (inputDevices.Keyboard.IsPressed(VK_LEFT) ||
            inputDevices.Keyboard.IsPressed('A') ||
            inputDevices.Joystick.IsLeftPressed())
        {
            _selectedCol--;
            NormalizeSelected();
            return true;
        }

        if (inputDevices.Keyboard.IsPressed(VK_RIGHT) ||
            inputDevices.Keyboard.IsPressed('D') ||
            inputDevices.Joystick.IsRightPressed())
        {
            _selectedCol++;
            NormalizeSelected();
            return true;
        }

        return false;
    }

private:
    void NormalizeSelected()
    {
        if (_selectedRow == -1) _selectedRow = Rows - 1;
        else if (_selectedRow == Rows) _selectedRow = 0;

        if (_selectedCol == -1) _selectedCol = Cols - 1;
        else if (_selectedCol == Cols) _selectedCol = 0;
    }
};
