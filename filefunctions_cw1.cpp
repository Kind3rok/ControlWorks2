#include <filesystem>
#include <fstream>
#include "flight.h"
#include "input.h"

bool IsDataCorrectCW1(std::ifstream& file) //The function checks if the data loaded from the file is valid
{
    std::string test_string{};
    int test_int{};
    std::string hours{};
    std::string minutes{};

    if (!file.eof())
    {
        GetLine(file, test_string, WITH_DIGITS, FILE_INPUT); //destination
        if (test_string.empty())
        {
            std::cout << "������ ���������� ������ ����������!" << std::endl;
            return false;
        }

        GetLine(file, test_string, ALMOST_ALL_DIGITS, FILE_INPUT); //number_flight
        if (test_string.empty())
        {
            std::cout << "������ ���������� ������ �����!" << std::endl;
            return false;
        }
        if (std::stoi(test_string) > INT_MAX)
        {
            std::cout << "������ ���������� ������ �����, ��������� ������������ ��������!" << std::endl;
            return false;
        }

        GetLine(file, test_string, WITH_DIGITS, FILE_INPUT); //type_flight
        if (test_string.empty())
        {
            std::cout << "������ ���������� ���� ��������!" << std::endl;
            return false;
        }

        std::getline(file, test_string, ':'); //time
        if (test_string.empty())
        {
            std::cout << "������ ���������� ������� ������!" << std::endl;
            return false;
        }
        if (strlen(test_string.c_str()) != 2)
        {
            std::cout << "������ ���������� ������� ������. �������� ������." << std::endl;
            return false;
        }
        
        hours = test_string;
        test_int = std::stoi(hours);
        if (test_int >= 24 || test_int < 0 || strlen(hours.c_str()) != 2) {
            std::cout << "�������� ������ �����, ������ ���� ���������� �����, ������ ���� 00 <= ����� < 24" << std::endl;
            return false;
        }
        std::getline(file, test_string);
        minutes = test_string;
        test_int = std::stoi(minutes);
        if (test_int >= 60 || test_int < 0 || strlen(minutes.c_str()) != 2) {
            std::cout
                << std::endl
                << "�������� ������ �����, ������ ���� ���������� �����, ������ ���� 00 <= ����� < 60" << std::endl;
            return false;
        }
       
        GetLine(file, test_string, WITHOUT_DIGITS, FILE_INPUT); //day
        if (test_string.empty())
        {
            std::cout << "������ ���������� ������� ������!" << std::endl;
            return false;
        }        

        while (file.get() != EOF); //to clean up possible residual information
    }
    else
        std::cout << "���� ����!" << std::endl;

    file.seekg(0, std::ios::beg);  //If everything went well, then return the pointer to the beginning of the file
    return true;
}

std::string CheckFile()
{
    std::error_code error{};

    std::string path{};
    bool isLoaded = false;

    std::ifstream file;

    do
    {
        std::cout << "������� ���� � �����: ";
        GetLine(std::cin, path, WITH_DIGITS, MANUAL_INPUT);

        if (!std::ifstream(path))
        {
            std::cout << "��������� ���� �� ������!" << std::endl;
            continue;
        }

        if (!std::filesystem::is_regular_file(path, error))
        {
            std::cout << "������, ������������ ����� �����!" << std::endl;
            continue;
        }

        file.open(path);

        if (!file)
        {
            std::cout << "������ �������� �����!" << std::endl;
            file.close();
        }
        else if (!IsDataCorrectCW1(file))
        {
            std::cout << "������ �����������!" << std::endl;
            file.close();
        }
        else
            isLoaded = true;
    } 
    while (!isLoaded);

    std::cout << "���� ������!" << std::endl;
    file.close();

    return path;
}

void GetListFromFile(Flight* List, int amount, std::string path = CheckFile())
{
    std::ifstream file(path);

    for (int i = 0; i < amount && !file.eof(); i++)
    {
        List[i].SetDestinationFromFile(file);
        List[i].SetNumberFlightFromFile(file);
        List[i].SetTypeFlightFromFile(file);
        List[i].SetTimeFromFile(file);
        List[i].SetDayFromFile(file);
    }

    std::cout << "������ ��������!" << std::endl;

    file.close();
}

void SaveToFile(Flight* List, int amount)
{
    std::ofstream file;
    std::string path{};
    bool isOpened = false;

    std::error_code error{};

    do
    {
        std::cout 
            << "������� ���� � ����� ��� ����������. "
            << "���� ������� ������ ��� � ���������� �����, ����������� ���� ����� �������� ���� � ��������� ���� ���������." << std::endl;
        GetLine(std::cin, path, WITH_DIGITS, MANUAL_INPUT);

        if (std::ifstream(path))
        {
            if (!std::filesystem::is_regular_file(path, error))
            {
                std::cout << "������, ������������ ����� �����!" << std::endl;
                continue;
            }

            std::cout 
                << "������ ���� ��� ����������!." << std::endl
                << "1 - ������������." << std::endl
                << "2 - ������� ������." << std::endl;

            if (GetKey(YES, NO) == NO)
                continue;
        }

        file.open(path, std::ios::trunc);

        if (!file)
            std::cout << "������ �������� �����!" << std::endl;
        else
            isOpened = true;
    } 
    while (!isOpened);

    Time outputTime{};
    std::string outputDay{}, outputDestination{}, outputTypeFlight{};
    int outputNumberFlight{};

    for (int i = 0; i < amount; i++)
    {
        outputDestination = List[i].GetDestination();
        outputNumberFlight = List[i].GetNumberFlight();
        outputTypeFlight = List[i].GetTypeFlight();
        outputTime = List[i].GetTime();
        outputDay = List[i].GetDay();
        
        if (i != 0) //separator between different apartments
            file << std::endl;

        file
            << outputDestination << std::endl
            << outputNumberFlight << std::endl
            << outputTypeFlight << std::endl
            << outputTime.hours << ':'
            << outputTime.minutes << std::endl 
            << outputDay;
    }
    std::cout << "������� ��������� � " << path << std::endl;
}

int CountStrings(std::string path)
{
    int stringsAmount{};

    std::ifstream file;
    file.open(path);
    std::string tmp{};

    while (!file.eof())
    {
        std::getline(file, tmp);
        stringsAmount++;
    }

    return stringsAmount;
}