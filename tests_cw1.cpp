#include "tests_cw1.h"
#include "flight.h"
#include "cw1_functions.h"
#include "filefunctions_cw1.h"
#include <fstream>
#include <filesystem>
#include <iostream>
#include "input.h"

bool UnitTestCW1::TestCaseOne() // test search by destination
{
	std::string test_file_path = "test1cw1.txt";
	if (!std::ifstream(test_file_path))
	{
		std::cout
			<< "Тест 1 провален." << std::endl
			<< "Ожидалось: файл открыт!" << std::endl
			<< "Получено: файл не найден!" << std::endl;
		return false;
	}
	const int flights_amount = 4;
	const int ans_amount = 2;
	std::string destination1{}, destination2{};
	const std::string  ansDestination = "Moscow"; 
	Flight* flights = nullptr;
	Flight* ansFlights = nullptr;
	if (!AllocateArray(flights, flights_amount))
	{
		std::cout << "Тест 1 провален. Ошибка выделения памяти" << std::endl;
		return false;
	}
	else
		flights = new Flight[flights_amount];

	GetListFromFile(flights, flights_amount, "test1cw1.txt");
	ansFlights = new Flight[ans_amount];
	SearchByDestination(flights, ansFlights, flights_amount, MODUL_TESTS);
	if (ansFlights != nullptr)
	{ 
		destination1 = ansFlights[0].GetDestination();
		destination2 = ansFlights[1].GetDestination();
	}

	if (destination1 != ansDestination)
	{
		std::cout
			<< "Тест 1 провален." << std::endl
			<< "Ожидалось: " << "рейс с пунктом назначения: " << ansDestination << std::endl
			<< "Получено: " << destination1 << std::endl;
		delete[] flights;
		delete[] ansFlights;
		return false;
	}
	if (destination2 != ansDestination)
	{
		std::cout
			<< "Тест 1 провален." << std::endl
			<< "Ожидалось: " << "рейс с  пунктом назначения: " << ansDestination << std::endl
			<< "Получено: " << destination2 << std::endl;
		delete[] flights;
		delete[] ansFlights;
		return false;
	}
	delete[] flights;
	delete[] ansFlights;
	return true;

}

bool UnitTestCW1::TestCaseTwo() // test search by day of the week
{
	std::string test_file_path = "test2cw1.txt";
	if (!std::ifstream(test_file_path))
	{
		std::cout
			<< "Тест 2 провален." << std::endl
			<< "Ожидалось: файл открыт!" << std::endl
			<< "Получено: файл не найден!" << std::endl;
		return false;
	}
	const int flights_amount = 4;
	const int ans_amount = 2;
	std::string day1{}, day2{};
	const std::string ansDay = "monday";
	Flight* flights = nullptr;
	Flight* ansFlights = nullptr;

	if (!AllocateArray(flights, flights_amount))
	{
		std::cout << "Тест 2 провален. Ошибка выделения памяти" << std::endl;
		return false;
	}
	else
		flights = new Flight[flights_amount];

	GetListFromFile(flights, flights_amount, "test2cw1.txt");
	ansFlights = new Flight[ans_amount];
	SearchByDay(flights, ansFlights, flights_amount, MODUL_TESTS);
	
	if (ansFlights != nullptr)
	{
		day1 = ansFlights[0].GetDay();
		day2 = ansFlights[1].GetDay();
	}


	if (day1 != ansDay)
	{
		std::cout
			<< "Тест 2 провален." << std::endl
			<< "Ожидалось: " << "рейс для заданного дня недели " << ansDay << std::endl
			<< "Получено: " << day1 << std::endl;
		delete[] flights;
		delete[] ansFlights;
		return false;
	}
	if (day2 != ansDay)
	{
		std::cout
			<< "Тест 2 провален." << std::endl
			<< "Ожидалось: " << "рейс для заданного дня недели: " << ansDay << std::endl
			<< "Получено: " << day2 << std::endl;
		delete[] flights;
		delete[] ansFlights;
		return false;
	}
	delete[] flights;
	delete[] ansFlights;
	return true;
}

bool UnitTestCW1::TestCaseThree() // check file where time is uncorrected 
{
	std::string test_file_path = "test3cw1.txt";
	if (!std::ifstream(test_file_path))
	{
		std::cout
			<< "Тест 3 провален." << std::endl
			<< "Ожидалось: файл открыт!" << std::endl
			<< "Получено: файл не найден!" << std::endl;
		return false;
	}
	const int flights_amount = 4;
	const int ans_amount = 2;
	Time time1{}, time2{};
	std::string day1{}, day2{};
	const std::string ansDay = "friday";
	std::string fulltime1{}, fulltime2{};
	const std::string ansTime = "12:30";
	Flight* flights = nullptr;
	Flight* ansFlights = nullptr;

	if (!AllocateArray(flights, flights_amount))
	{
		std::cout << "Тест 3 провален. Ошибка выделения памяти" << std::endl;
		return false;
	}
	else
		flights = new Flight[flights_amount];

	GetListFromFile(flights, flights_amount, "test3cw1.txt");
	ansFlights = new Flight[ans_amount];
	SearchByDayAndTime(flights, ansFlights, flights_amount, MODUL_TESTS);

	if (ansFlights != nullptr)
	{
		day1 = ansFlights[0].GetDay();
		day2 = ansFlights[1].GetDay();
		time1 = ansFlights[0].GetTime();
		fulltime1 = time1.hours + ':' + time1.minutes;
		time2 = ansFlights[1].GetTime();
		fulltime2 = time2.hours + ':' + time2.minutes;
	}

	if (fulltime1 != ansTime)
	{
		std::cout
			<< "Тест 3 провален." << std::endl
			<< "Ожидалось: " << "рейс с временем " << ansTime << std::endl
			<< "Получено: " << fulltime1 << std::endl;
		delete[] flights;
		delete[] ansFlights;
		return false;
	}
	if (fulltime2 != ansTime)
	{
		std::cout
			<< "Тест 3 провален." << std::endl
			<< "Ожидалось: " << "рейс с временем " << ansTime << std::endl
			<< "Получено: " << fulltime2 << std::endl;
		delete[] flights;
		delete[] ansFlights;
		return false;
	}
	if (day1 != ansDay)
	{
		std::cout
			<< "Тест 3 провален." << std::endl
			<< "Ожидалось: " << "рейс для заданного дня недели " << ansDay << std::endl
			<< "Получено: " << day1 << std::endl;
		delete[] flights;
		delete[] ansFlights;
		return false;
	}
	if (day2 != ansDay)
	{
		std::cout
			<< "Тест 3 провален." << std::endl
			<< "Ожидалось: " << "рейс для заданного дня недели: " << ansDay << std::endl
			<< "Получено: " << day2 << std::endl;
		delete[] flights;
		delete[] ansFlights;
		return false;
	}
	delete[] flights;
	delete[] ansFlights;
	return true;

}

bool UnitTestCW1::TestCaseFour() // test check apartment valid file
{
	std::string test_file_path = "test4cw1.txt";
	if (!std::ifstream(test_file_path))
	{
		std::cout
			<< "Тест 4 провален." << std::endl
			<< "Ожидалось: файл открыт!" << std::endl
			<< "Получено: файл не найден!" << std::endl;
		return false;
	}

	std::ifstream file(test_file_path);
	if (!IsDataCorrectCW1(file))
	{
		std::cout
			<< "Тест 4 провален." << std::endl
			<< "Ожидалось: данные корректны " << std::endl
			<< "Получено: данные некорректны" << std::endl;
		return false;
	}
	file.close();
	return true;
}

bool UnitTestCW1::TestCaseFive() // zero flights
{
	std::string test_file_path = "test5cw1.txt";
	if (!std::ifstream(test_file_path))
	{
		std::cout
			<< "Тест 5 провален." << std::endl
			<< "Ожидалось: файл открыт!" << std::endl
			<< "Получено: файл не найден!" << std::endl;
		return false;
	}
	const int flights_amount(0);
	Flight* flights = nullptr;
	if (AllocateArray(flights, flights_amount))
	{
		std::cout << "Тест 5 провален. Ошибка выделения памяти!" << std::endl;
		return false;
	}

	return true;
}

void UnitTestCW1::RunAllTests()
{
	UnitTestCW1 test{};

	if (test.TestCaseOne() && test.TestCaseTwo() && test.TestCaseThree() && test.TestCaseFour() && test.TestCaseFive())
	{
		system("cls");
		std::cout << "Все модульные тесты пройдены!" << std::endl;
	}
	else
		std::cout << "Модульные тесты не пройдены." << std::endl;
}
