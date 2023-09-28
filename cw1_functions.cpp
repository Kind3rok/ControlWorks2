#include "input.h"
#include "filefunctions_cw1.h"
#include <algorithm>

bool AllocateArray(Flight* flights , int amount)  // checking the possibility of adding a client
{
    if (amount == 0)
    {
        std::cout << "Ошибка выделения памяти: нельзя выделять память для 0 элементов" << std::endl; 
        return false;
    }

    try
    {
        flights = new Flight[amount];
    }
    catch (const std::bad_alloc& error)
    {
        std::cout
            << "Ошибка выделения памяти: " << error.what() << std::endl
            << "Попробуйте изменить количество рейсов" << std::endl;
        if (flights != nullptr)
            delete[] flights;
        return false;
    }
    if (flights != nullptr)
        delete[] flights;
    return true;
}

void ShowFlight(Flight* flights, int amount)
{
    int id = 1;
    for (int i = 0; i < amount; i++, id++)
    {
        std::cout << "Рейс # " << id << std::endl;
        flights[i].ShowFlight();
    }
}

void FillFlight(Flight* flights, int amount)
{
    std::cout << std::endl;
    int flight_id = 1;
    for (int i = 0; i < amount; i++, flight_id++) 
    {
        std::cout << "Заполните информацию о рейсе # " << flight_id << "." << std::endl;
        flights[i].SetDestination();
        flights[i].SetTime();
        flights[i].SetNumberFlight();
        flights[i].SetTypeFlight();
        flights[i].SetDay();
        std::cout << std::endl;
    }
}
void SearchByDestination(Flight* flights, Flight* ansFlights, int amount, int isTest)
{
    bool isThereAtLeastOne = false;
    int counter(0);
    std::string destination{};
    if (isTest == MODUL_TESTS)
    {
        destination = "Moscow";
    }
    if (isTest == MANUAL_INPUT)
    {
        std::cout << "Введите пункт назначения, по которому необходимо произвести поиск." << std::endl;
        GetLine(std::cin, destination, WITH_DIGITS, MANUAL_INPUT);
    }

    for (int i = 0; i < amount; i++)
    {
        if (flights[i].GetDestination() == destination)
        {
           isThereAtLeastOne = true;
            flights[i].ShowFlight();
            counter++;           
        }
    }
    if (!(isThereAtLeastOne))
        std::cout << "Рейсов в заданном диапазоне нет!" << std::endl;
    
    if (isThereAtLeastOne)
    {
        int user_choice{};
        if (isTest == MANUAL_INPUT)
        {
            std::cout << "Записать результат в файл?" << std::endl;
            std::cout << "1 - Да, 2 - Нет. ESC - выход из программы." << std::endl;
            user_choice = GetKey(YES, NO);
        }
        if (user_choice == YES || isTest == MODUL_TESTS)
        {
            if(isTest == MANUAL_INPUT)
                ansFlights = new Flight[counter];
            for (int i = 0, j = 0; i < amount && j < counter; i++)
                if (flights[i].GetDestination() == destination)
                    ansFlights[j++] = flights[i];

            if (isTest == MANUAL_INPUT)
            {
                SaveToFile(ansFlights, counter);
                delete[] ansFlights;
            }
        }

        else if (user_choice == QUIT)
        {
            delete[] flights;
            exit(EXIT_SUCCESS);
        }
    }
}

void SearchByDay(Flight* flights, Flight* ansFlights, int amount, int isTest)
{
    bool isThereAtLeastOne = false;
    int counter(0);
    std::string day{};
    if (isTest == MODUL_TESTS)
    {
        day = "monday";
    }
    if (isTest == MANUAL_INPUT)
    {
        std::cout << "Введите день недели, по которому необходимо произвести поиск." << std::endl;
        GetLine(std::cin, day, WITHOUT_DIGITS, MANUAL_INPUT);
    }
    for (int i = 0; i < amount; i++)
    {
        if (flights[i].GetDay() == day)
        {
            isThereAtLeastOne = true;
            flights[i].ShowFlight();
            counter++; 
        }
    }
    if (!isThereAtLeastOne)
        std::cout << "Рейсов в заданном диапазоне нет!" << std::endl;
    if (isThereAtLeastOne)
    {
        int user_choice{};
        if (isTest == MANUAL_INPUT)
        {
            std::cout << "Записать результат в файл?" << std::endl;
            std::cout << "1 - Да, 2 - Нет. ESC - выход из программы." << std::endl;
            user_choice = GetKey(YES, NO);
        }
        if (user_choice == YES || isTest == MODUL_TESTS)
        {
            if (isTest == MANUAL_INPUT)
                ansFlights = new Flight[counter];
            for (int i = 0, j = 0; i < amount && j < counter; i++)
                if (flights[i].GetDay() == day)
                    ansFlights[j++] = flights[i];

            if (isTest == MANUAL_INPUT)
            {
                SaveToFile(ansFlights, counter);
                delete[] ansFlights;
            }
        }

        else if (user_choice == QUIT)
        {
            delete[] flights;
            exit(EXIT_SUCCESS);
        }
    }
}


void SearchByDayAndTime(Flight* flights, Flight* ansFlights, int amount, int isTest)
{
    bool isThereAtLeastOne = false;
    int counter(0);
    std::string day{}, hours{}, minutes{};
    Time time{};
    if (isTest == MODUL_TESTS)
    {
        day = "friday";
        hours = "12";
        minutes = "29";
    }
    if (isTest == MANUAL_INPUT)
    {
        std::cout << "Введите день недели, по которому необходимо произвести поиск." << std::endl;
        GetLine(std::cin, day, WITHOUT_DIGITS, MANUAL_INPUT);
        std::cout << "Введите время вылета позже которого необходимо произвести поиск." << std::endl;
        InputTime(hours, minutes);
    }

    for (int i = 0; i < amount; i++)
    {
        if (flights[i].GetDay() == day && std::stoi(flights[i].GetTime().hours) >= std::stoi(hours) && std::stoi(flights[i].GetTime().minutes) > std::stoi(minutes)) 
        {
            isThereAtLeastOne = true;
            flights[i].ShowFlight();
            counter++;
        }
    }
    if (!isThereAtLeastOne)
        std::cout << "Рейсов в заданном диапазоне нет!" << std::endl;
    if (isThereAtLeastOne)
    {
        int user_choice{};
        if (isTest == MANUAL_INPUT)
        {
            std::cout << "Записать результат в файл?" << std::endl;
            std::cout << "1 - Да, 2 - Нет. ESC - выход из программы." << std::endl;
            user_choice = GetKey(YES, NO);
        }
        if (user_choice == YES || isTest == MODUL_TESTS)
        {
            if (isTest == MANUAL_INPUT)
                ansFlights = new Flight[counter];
            for (int i = 0, j = 0; i < amount && j < counter; i++)
                if (flights[i].GetDay() == day && std::stoi(flights[i].GetTime().hours) >= std::stoi(hours) && std::stoi(flights[i].GetTime().minutes) > std::stoi(minutes))
                    ansFlights[j++] = flights[i];

            if (isTest == MANUAL_INPUT)
            {
                SaveToFile(ansFlights, counter);
                delete[] ansFlights;
            }
        }

        else if (user_choice == QUIT)
        {
            delete[] flights;
            exit(EXIT_SUCCESS);
        }
    }
}
bool IsListEmpty(Flight* flights, int amount)
{
    for (int i = 0; i < amount; i++)
    {
        if (!flights[i].IsEmpty())
            return false;
    }
    return true;
}