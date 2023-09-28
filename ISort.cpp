#include "ISort.h"
#include "input.h"


void BubbleSort::Sort(std::vector<int>& arr)
{
    size_t n = arr.size();
    for (size_t i = 0; i < n - 1; i++)
    {
        for (size_t j = 0; j < n - i - 1; j++)
        {
            if (abs(arr[j]) < abs(arr[j + 1]))
            {
                std::swap(arr[j], arr[j + 1]);
                _swapCount++;
            }
            _comparisonCount++;
        }
    }
}


void SelectionSort::Sort(std::vector<int>& arr)
{
    size_t n = arr.size(), minIndex{};
    for (size_t i = 0; i < n - 1; i++)
    {
        minIndex = i;
        for (size_t j = i + 1; j < n; j++)
        {
            if (abs(arr[j]) > abs(arr[minIndex]))
                minIndex = j;
            _comparisonCount++;
        }

        if (minIndex != i)
        {
            std::swap(arr[i], arr[minIndex]);
            _swapCount++;
        }
    }
}


void InsertionSort::Sort(std::vector<int>& arr)
{
    int temp = 0;
    bool same_digit{};
    size_t n = arr.size(), i{}, j{};
    for (i = 1; i < n; i++)
    {
        same_digit = false;
        j = i;
        temp = arr[i];
        while (j > 0 && abs(arr[j - 1]) < abs(temp))
        {
            same_digit = true;
            arr[j] = arr[j - 1];
            j--;
            _comparisonCount++;
        }
        if (abs(arr[j]) >= abs(temp))
            _comparisonCount++;
        if (same_digit)
        {
            arr[j] = temp;
            _swapCount++;
        }
    }
}


void ShellSort::Sort(std::vector<int>& arr)
{
    size_t n = arr.size(), gap = n / 2, i{}, j{};
    int temp{};
    bool same_digit{};
    _swapCount = 0; 

    while (gap > 0)
    {
        for (i = gap; i < n; i++)
        {
            same_digit = false;
            j = i;
            temp = arr[i];
            while (j >= gap && abs(arr[j - gap]) < abs(temp))
            {
                same_digit = true;
                _comparisonCount++;
                arr[j] = arr[j - gap];
                j -= gap;
            }
            if (abs(arr[j]) >= abs(temp))
                _comparisonCount++;
            if (same_digit)
            {
                arr[j] = temp;
                _swapCount++;
            }
        }
        gap /= 2;
    }
}

void QuickSort::SortPartition(std::vector<int>& arr, int left, int right)
{
    int i = left, j = right;
    int pivot = arr[(left + right) / 2];

    while (i <= j)
    {
        while (abs(arr[i]) > abs(pivot))
        {
            i++;
            _comparisonCount++;
        }
        _comparisonCount++;

        while (abs(arr[j]) < abs(pivot))
        {
            j--;
            _comparisonCount++;
        }
        _comparisonCount++;

        if (i <= j)
        {
            std::swap(arr[i++], arr[j--]);
            _swapCount++;
        }
    }

    if (left < j)
    {
        SortPartition(arr, left, j);
    }

    if (i < right)
    {
        SortPartition(arr, i, right);
    }
}

void QuickSort::Sort(std::vector<int>& arr)
{
    SortPartition(arr, 0, static_cast<int>(arr.size()) - 1);
}
