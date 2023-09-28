#include "tests_cw2.h"
#include "predator.h"
#include "cw2_functions.h"
#include "filefunctions_cw2.h"
#include <filesystem>
#include <fstream>


bool UnitTestCW2::TestCaseOne() // boot from valid file
{
	std::string test_file_path = "test1cw2.txt"; 
	if (!std::ifstream(test_file_path))
	{
		std::cout
			<< "Тест 1 провален." << std::endl
			<< "Ожидалось: файл открыт!" << std::endl
			<< "Получено: файл не найден!" << std::endl;
		return false;
	}

	std::string path = "test1cw2.txt";
	std::ifstream file(test_file_path);
	if (!IsDataCorrectCW2(file))
	{
		std::cout
			<< "Тест 1 провален." << std::endl
			<< "Ожидалось: данные корректны " << std::endl
			<< "Получено: данные некорректны" << std::endl;
		return false;
	}
	file.close();
	return true;
}

bool UnitTestCW2::TestCaseTwo() // check file where habitat is digit
{
	std::string test_file_path = "test2cw2.txt";
	if (!std::ifstream(test_file_path))
	{
		std::cout
			<< "Тест 2 провален." << std::endl
			<< "Ожидалось: файл открыт!" << std::endl
			<< "Получено: файл не найден!" << std::endl;
		return false;
	}
	std::string path = "test2cw2.txt";
	std::ifstream file(path);
	if (IsDataCorrectCW2(file))
	{
		std::cout
			<< "Тест 2 провален." << std::endl
			<< "Ожидалось: " << "данные некорректны " << std::endl
			<< "Получено: " << "данные корректны" << std::endl;
		return false;
	}
	file.close();
	system("cls");
	return true;
}

bool UnitTestCW2::TestCaseThree() // check file where way of eating is digit
{
	std::string test_file_path = "test3cw2.txt";
	if (!std::ifstream(test_file_path))
	{
		std::cout
			<< "Тест 3 провален." << std::endl
			<< "Ожидалось: файл открыт!" << std::endl
			<< "Получено: файл не найден!" << std::endl;
		return false;
	}
	std::string path = "test3cw2.txt";
	std::ifstream file(path);
	if (IsDataCorrectCW2(file))
	{
		std::cout
			<< "Тест 3 провален." << std::endl
			<< "Ожидалось: " << "данные некорректны " << std::endl
			<< "Получено: " << "данные корректны" << std::endl;
		return false;
	}
	file.close();
	system("cls");
	return true;
}
	
bool UnitTestCW2::TestCaseFour() // check file where weight or speed is not a digit
{
	std::string test_file_path = "test4cw2.txt";
	if (!std::ifstream(test_file_path))
	{
		std::cout
			<< "Тест 4 провален." << std::endl
			<< "Ожидалось: файл открыт!" << std::endl
			<< "Получено: файл не найден!" << std::endl;
		return false;
	}
	std::string path = "test4cw2.txt";
	std::ifstream file(path);
	if (IsDataCorrectCW2(file))
	{
		std::cout
			<< "Тест 4 провален." << std::endl
			<< "Ожидалось: " << "данные некорректны " << std::endl
			<< "Получено: " << "данные корректны" << std::endl;
		return false;
	}
	file.close();
	system("cls");
	return true;
}

bool UnitTestCW2::TestCaseFive() // check valid file
{
	std::string test_file_path = "test5cw2.txt";
	if (!std::ifstream(test_file_path))
	{
		std::cout
			<< "Тест 5 провален." << std::endl
			<< "Ожидалось: файл открыт!" << std::endl
			<< "Получено: файл не найден!" << std::endl;
		return false;
	}
	std::string path = "test5cw2.txt";
	std::ifstream file(path);
	if (!IsDataCorrectCW2(file))
	{
		std::cout
			<< "Тест 5 провален." << std::endl
			<< "Ожидалось: " << "данные корректны " << std::endl
			<< "Получено: " << "данные некорректны" << std::endl;
		return false;
	}
	file.close();
	system("cls");
	return true;
}

void UnitTestCW2::RunAllTests()
{
	UnitTestCW2 test{};
	if (test.TestCaseOne() && test.TestCaseTwo() && test.TestCaseThree() && test.TestCaseFour() && test.TestCaseFive())
		std::cout << "Все модульные тесты пройдены!" << std::endl;
	else
		std::cout << "Модульные тесты не пройдены." << std::endl;
}
