#pragma once

#include <lib/Object.h>
#include <lib/Exceptions.h>
#include <lib/Memory.h>

template<class T>
class Matrix : public Object
{
    int _rows;
    int _cols;
    T* _items;

public:
    Matrix(int rows, int cols)
    {
        _rows = rows;
        _cols = cols;
        _items = Memory::AllocAndZero<T>(_rows * _cols);
    }

    ~Matrix()
    {
        Memory::Release(_items);
    }

    T& GetItem(int row, int col)
    {
        CheckBounds(row, col);
        return _items[row * _cols + col];
    }

private:
    void CheckBounds(int row, int col)
    {
        if (row < 0 || row >= _rows) throw IndexOutOfBoundsException();
        if (col < 0 || col >= _cols) throw IndexOutOfBoundsException();
    }
};
