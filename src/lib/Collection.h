#pragma once

#include <lib/Object.h>
#include <lib/IComparator.h>

template<class T>
class Collection : public Object
{
public:
    virtual T& operator[](int index) = 0;

    virtual int GetCount() = 0;

    T& First()
    {
        return (*this)[0];
    }

    T& Last()
    {
        return (*this)[GetCount() - 1];
    }

    void Sort(IComparator<T>& comparator)
    {
        Sort(0, GetCount() - 1, comparator);
    }

private:
    void Sort(int startIndex, int endIndex, IComparator<T>& comparator)
    {
        int i = startIndex;
        int j = endIndex;
        T& middle = (*this)[(i + j) / 2];
        while (i <= j)
        {
            while (comparator.Compare((*this)[i], middle) < 0) i++;
            while (comparator.Compare((*this)[j], middle) > 0) j--;
            if (i <= j)
            {
                T temp = (*this)[i];
                (*this)[i] = (*this)[j];
                (*this)[j] = temp;
                i++;
                j--;
            }
        }
        if (j > startIndex) Sort(startIndex, j, comparator);
        if (i < endIndex) Sort(i, endIndex, comparator);
    }
};
