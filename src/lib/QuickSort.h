#pragma once

#include <lib/Object.h>
#include <lib/IArray.h>
#include <lib/IComparator.h>

template<class T>
class QuickSort : public Object
{
public:
    void Sort(IArray<T>& range, IComparator<T>& comparator)
    {
        Sort(range, 0, range.GetCount() - 1, comparator);
    }

private:
    void Sort(IArray<T>& range, int startIndex, int endIndex, IComparator<T>& comparator)
    {
        int i = startIndex;
        int j = endIndex;
        T& middle = range[(i + j) / 2];
        while (i <= j)
        {
            while (comparator.Compare(range[i], middle) < 0) i++;
            while (comparator.Compare(range[j], middle) > 0) j--;
            if (i <= j)
            {
                T temp = range[i];
                range[i] = range[j];
                range[j] = temp;
                i++;
                j--;
            }
        }
        if (j > startIndex) Sort(range, startIndex, j, comparator);
        if (i < endIndex) Sort(range, i, endIndex, comparator);
    }
};
