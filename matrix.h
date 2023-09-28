#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include "ISort.h"

class Matrix
{
	std::vector<int> _unsortedColumns{};
	std::vector<std::vector<int>> _sortedColumns{};
public:

	void StartSort(std::vector<std::vector<int>>& arr, int rows, int columns, std::vector<ISort*>::iterator& it);
	void ShowSortedMatrix(int rows, int columns, std::vector<ISort*>::iterator& it);
	bool IsSorted(std::vector<int>& arr);
	std::vector<std::vector<int>> GetSortedColumns() { return _sortedColumns; };

};

#endif