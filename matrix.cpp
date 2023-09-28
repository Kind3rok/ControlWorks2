#include "matrix.h"
#include "ISort.h"
#include "input.h"


bool Matrix::IsSorted(std::vector<int>& arr)
{
    for (size_t i = 1; i < arr.size(); i++)
    {
        if (arr[i] > arr[i - 1])
        {
            return false;
        }
    }
    return true;
}

void Matrix::StartSort(std::vector<std::vector<int>>& arr, int rows, int columns, std::vector<ISort*>::iterator& it)
{

    for (int i = 0; i < columns; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            _unsortedColumns.push_back(arr[j][i]);
        }
        if (!_unsortedColumns.empty())
        {
            (*it)->Sort(_unsortedColumns);
            _sortedColumns.push_back(_unsortedColumns);
            _unsortedColumns.clear();
        }
    }
}

void Matrix::ShowSortedMatrix(int rows, int columns, std::vector<ISort*>::iterator& it)
{
    std::cout << std::endl << (*it)->GetSortName() << std::endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            std::cout << _sortedColumns[j][i] << ' ';
        }
        std::cout << std::endl;
    }
}
