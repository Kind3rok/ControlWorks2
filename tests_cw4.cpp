#include "tests_cw4.h"
#include "cw4_functions.h"
#include "filefunctions_cw4.h"
#include <iostream>
#include <fstream>
#include <filesystem>


bool UnitTestCW4::TestCaseOne() // test modify 1 substring
{
	size_t sequence_size = 2;
	std::string
		testString = "длинношеее животное",
		resultString{},
		expectedResult = "дли{н, 2}ош{е, 3} животное";

	StartModify(testString, resultString, sequence_size);
	if (resultString != expectedResult)
	{
		std::cout
			<< "Тест 1 провален." << std::endl
			<< "Ожидалось: " << expectedResult << std::endl
			<< "Получено: " << resultString << std::endl;
		return false;
	}

	return true;
}

bool UnitTestCW4::TestCaseTwo() // test modify more than 1 substring
{
	size_t sequence_size = 3;
	std::string
		testString = "testovayaaa stroooka 1122234444 stttr",
		resultString{},
		expectedResult = "testovay{a, 3} str{o, 3}ka 11{2, 3}3{4, 4} s{t, 3}r";

	StartModify(testString, resultString, sequence_size);
	if (resultString != expectedResult)
	{
		std::cout
			<< "Тест 2 провален." << std::endl
			<< "Ожидалось: " << expectedResult << std::endl
			<< "Получено: " << resultString << std::endl;
		return false;
	}

	return true;
}

bool UnitTestCW4::TestCaseThree() // test restore 1 substring
{
	std::string
		testString = "дли{н, 2}ош{е, 3} животное",
		resultString{},
		expectedResult = "длинношеее животное";
	bool error = false;
	StartRestore(testString, resultString, error);
	if (resultString != expectedResult)
	{
		std::cout
			<< "Тест 3 провален." << std::endl
			<< "Ожидалось: " << expectedResult << std::endl
			<< "Получено: " << resultString << std::endl;
		return false;
	}

	return true;
}

bool UnitTestCW4::TestCaseFour() // test restore more than 1 substring
{
	std::string
		testString = "testovay{a, 3} str{o, 3}ka 11{2, 3}3{4, 4} s{t, 3}r",
		resultString{},
		expectedResult = "testovayaaa stroooka 1122234444 stttr";
	bool error = false;
	StartRestore(testString, resultString, error);
	if (resultString != expectedResult)
	{
		std::cout
			<< "Тест 4 провален." << std::endl
			<< "Ожидалось: " << expectedResult << std::endl
			<< "Получено: " << resultString << std::endl;
		return false;
	}

	return true;
}

bool UnitTestCW4::TestCaseFive() // check getting text from file
{
	std::string
		path = "test5cw4.txt",
		resultString{},
		expectedResult = "testovayaaa stroooka 1122234444 stttr";

	if (!std::ifstream(path))
	{
		std::cout
			<< "Тест 5 провален." << std::endl
			<< "Ожидалось: " << "файл открыт!" << std::endl
			<< "Получено: " << "файл не найден!" << std::endl;
		return false;
	}

	GetTextFromFile(resultString, path);

	if (resultString != expectedResult)
	{
		std::cout
			<< "Тест 5 провален." << std::endl
			<< "Ожидалось: " << expectedResult << std::endl
			<< "Получено: " << resultString << std::endl;
		return false;
	}

	return true;
}


void UnitTestCW4::RunAllTests()
{
	UnitTestCW4 test{};
	if (test.TestCaseOne() && test.TestCaseTwo() && test.TestCaseThree() && test.TestCaseFour() && test.TestCaseFive())
	{
		system("cls");
		std::cout << "Все модульные тесты пройдены!" << std::endl;
	}
	else
		std::cout << "Модульные тесты не пройдены." << std::endl;
}
