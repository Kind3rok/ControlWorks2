#ifndef CW3_FUNCTIONS_H
#define CW3_FUNCTIONS_H

#include <vector>
#include "ISort.h"
#include "matrix.h"


void ShowUnsortedMatrix(std::vector<std::vector<int>>& arr, int rows, int columns);
void ShowComparisonTable(std::vector<ISort*>& sorts);
void FillMatrix(std::vector<std::vector<int>>& matrix, int rows, int columns);
void FillMatrixRandomly(std::vector<std::vector<int>>& matrix, int rows, int columns);
void GoSort(std::vector<std::vector<int>>& arr, int rows, int columns, std::vector<ISort*>& sorts, std::vector<Matrix*>& matrices);
void ShowResults(std::vector<std::vector<int>>& arr, int rows, int columns, std::vector<ISort*>& sorts, std::vector<Matrix*>& matrices);


#endif