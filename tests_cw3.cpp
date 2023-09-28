#include "tests_cw3.h"
#include "cw3_functions.h"
#include "filefunctions_cw3.h"
#include "matrix.h"

void UnitTestCW3::PrintArray(std::vector<int> array)
{
	for (size_t i = 0; i < array.size(); i++)
		std::cout << array[i] << ' ';
	std::cout << std::endl;
}

bool UnitTestCW3::TestCaseOne() // test bubble sort
{
	std::vector<int> array{ 9, 5, 3, 2, 7, 4, 0, 1, 6, 8 };
	std::vector<int> answer{ 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	Matrix matrix{};
	BubbleSort bubble_sort{};
	bubble_sort.Sort(array);
	if (!matrix.IsSorted(array))
	{
		std::cout
			<< "Тест 1 провален." << std::endl
			<< "Ожидалось: " << "отсортированные элементы: " << std::endl;
		PrintArray(answer);
		std::cout << "Получено: " << std::endl;
		PrintArray(array);
		return false;
	}
	
	return true;

}

bool UnitTestCW3::TestCaseTwo() // test selection sort
{
	std::vector<int> array{ 9, 5, 3, 2, 7, 4, 0, 1, 6, 8 };
	std::vector<int> answer{ 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	Matrix matrix{};
	SelectionSort selection_sort{};
	selection_sort.Sort(array);
	if (!matrix.IsSorted(array))
	{
		std::cout
			<< "Тест 2 провален." << std::endl
			<< "Ожидалось: " << "отсортированные элементы: " << std::endl;
		PrintArray(answer);
		std::cout << "Получено: " << std::endl;
		PrintArray(array);
		return false;
	}
	return true;
}

bool UnitTestCW3::TestCaseThree() // test insertion sort
{
	std::vector<int> array{ 9, 5, 3, 2, 7, 4, 0, 1, 6, 8 };
	std::vector<int> answer{ 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	Matrix matrix{};
	InsertionSort insertion_sort{};
	insertion_sort.Sort(array);
	if (!matrix.IsSorted(array))
	{
		std::cout
			<< "Тест 3 провален." << std::endl
			<< "Ожидалось: " << "отсортированные элементы: " << std::endl;
		PrintArray(answer);
		std::cout << "Получено: " << std::endl;
		PrintArray(array);
		return false;
	}
	return true;
}

bool UnitTestCW3::TestCaseFour() // test shell sort
{
	std::vector<int> array{ 9, 5, 3, 2, 7, 4, 0, 1, 6, 8 };
	std::vector<int> answer{ 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	Matrix matrix{};
	ShellSort shell_sort{};
	shell_sort.Sort(array);
	if (!matrix.IsSorted(array))
	{
		std::cout
			<< "Тест 4 провален." << std::endl
			<< "Ожидалось: " << "отсортированные элементы: " << std::endl;
		PrintArray(answer);
		std::cout << "Получено: " << std::endl;
		PrintArray(array);
		return false;
	}
	return true;
}

bool UnitTestCW3::TestCaseFive() // test quick sort
{
	std::vector<int> array{ 9, 5, 3, 2, 7, 4, 0, 1, 6, 8 };
	std::vector<int> answer{ 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	Matrix matrix{};
	QuickSort quick_sort{};
	quick_sort.Sort(array);
	if (!matrix.IsSorted(array))
	{
		std::cout
			<< "Тест 5 провален." << std::endl
			<< "Ожидалось: " << "отсортированные элементы: " << std::endl;
		PrintArray(answer);
		std::cout << "Получено: " << std::endl;
		PrintArray(array);
		return false;
	}
	return true;
}



void UnitTestCW3::RunAllTests()
{
	UnitTestCW3 test{};
	if (test.TestCaseOne() && test.TestCaseTwo() && test.TestCaseThree() && test.TestCaseFour() && test.TestCaseFive())
		std::cout << "Все модульные тесты пройдены!" << std::endl;
	else
		std::cout << "Модульные тесты не пройдены." << std::endl;
}
