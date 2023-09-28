#include <filesystem>
#include <fstream>
#include "input.h"
#include <iostream>
#include "cw3_functions.h"

bool IsDataCorrectCW3(std::ifstream& file) //The function checks if the data loaded from the file is valid
{
    int test_int{};
    int rows{}, columns{};
    std::string sort_name{};

    if (!file.eof())
    {
        file >> rows;
        if (rows > INT_MAX)
        {
            std::cout
                << "Ошибка считывания количества строк"
                << ", превышено максимальное значение!" << std::endl;
            return false;
        }
        if (file.fail() || rows <= 0)
        {
            std::cout << "Ошибка считывания количества строк" << std::endl;
            return false;
        }

        file >> columns;
        if (columns > INT_MAX)
        {
            std::cout
                << "Ошибка считывания количества столбцов"
                << ", превышено максимальное значение!" << std::endl;
            return false;
        }
        if (file.fail() || columns <= 0)
        {
            std::cout << "Ошибка считывания количества столбцов" << std::endl;
            return false;
        }

        file.get();
        GetLine(file, sort_name, WITHOUT_DIGITS, FILE_INPUT);

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                file >> test_int;
                if (test_int > INT_MAX)
                {
                    std::cout
                        << "Ошибка считывания значения ячейки"
                        << i + 1 << ' ' << j + 1
                        << ", превышено максимальное значение!" << std::endl;
                    return false;
                }
                if (file.fail())
                {
                    std::cout
                        << "Ошибка считывания значения ячейки"
                        << i + 1 << ' ' << j + 1 << std::endl;
                    return false;
                }
            }
        }
        while (file.get() != EOF);
    }
    else 
        std::cout << "Файл пуст!";
    file.seekg(0, std::ios::beg);  //If everything went well, then return the pointer to the beginning of the file
    return true;
}

std::string CheckFileCW3()
{
    std::error_code error{};

    std::string path{};
    bool isLoaded = false;

    std::ifstream file;

    do
    {
        std::cout << "Введите путь к файлу: ";
        GetLine(std::cin, path, WITH_DIGITS, MANUAL_INPUT);

        if (!std::ifstream(path))
        {
            std::cout << "Указанный файл не найден!" << std::endl;
            continue;
        }

        if (!std::filesystem::is_regular_file(path, error))
        {
            std::cout << "Ошибка, недопустимый адрес файла!" << std::endl;
            continue;
        }

        file.open(path);

        if (!file)
        {
            std::cout << "Ошибка открытия файла!" << std::endl;
            file.close();
        }
        else if (!IsDataCorrectCW3(file))
        {
            std::cout << "Данные некорректны!" << std::endl;
            file.close();
        }
        else
            isLoaded = true;
    } 
    while (!isLoaded);

    std::cout << "Файл открыт!" << std::endl;
    file.close();

    return path;
}

void GetMatrixFromFile(std::vector<std::vector<int>>& matrix, int& rows, int& columns, std::string& path)
{
    std::ifstream file(path);
    std::string sort_name{};

    file >> rows >> columns;
    file.get();
    GetLine(file, sort_name, WITHOUT_DIGITS, FILE_INPUT);

    matrix.resize(rows);
    for (int i = 0; i < rows; i++)
    {
        matrix[i].resize(columns);
        for (int j = 0; j < columns; j++)
            file >> matrix[i][j];
    }

    std::cout << "Матрица загружена!" << std::endl;
    file.close();
}

void SaveToFile(std::vector<ISort*>& sorts, std::vector<Matrix*>& matrices, std::vector<std::vector<int>>& arr, int rows, int columns)
{
    std::ofstream file;
    std::string path{};
    bool isOpened = false;

    std::error_code error{};

    do
    {
        std::cout
            << "Введите путь к файлу для сохранения. "
            << "Если указать только имя и расширение файла, стандартным путём будет являться путь к исходному коду программы." << std::endl;
        GetLine(std::cin, path, WITH_DIGITS, MANUAL_INPUT);
        if (std::ifstream(path))
        {
            if (!std::filesystem::is_regular_file(path, error))
            {
                std::cout << "Ошибка, недопустимый адрес файла!" << std::endl;
                continue;
            }

            std::cout
                << "Данный файл уже существует!." << std::endl
                << "1 - Перезаписать." << std::endl
                << "2 - Выбрать другой." << std::endl;

            if (GetKey(YES, NO) == NO)
                continue;
        }

        file.open(path, std::ios::trunc);

        if (!file)
            std::cout << "Ошибка открытия файла!" << std::endl;
        else
            isOpened = true;
    } 
    while (!isOpened);

    file << rows << ' ' << columns << std::endl;  //input rows and columns

    file << "Изначальный массив: " << std::endl; //input unsorted matrix
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            file << arr[i][j] << ' ';
        }
        file << std::endl;
    }


    std::vector<Matrix*>::iterator m_it = matrices.begin();  //input sorted matrices
    std::vector<ISort*>::iterator it = sorts.begin();
    for (; (it != sorts.end()) && (m_it != matrices.end()); it++, m_it++)
    {
        file << std::endl << (*it)->GetSortName() << std::endl;
        std::vector<std::vector<int>> sortedColumns = (*m_it)->GetSortedColumns();
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                file << sortedColumns[j][i] << ' ';
            }

            file << std::endl;
        }
    }

    for (it = sorts.begin(); it != sorts.end(); it++) //input comparison table
    {
        file 
            << std::endl << (*it)->GetSortName() << std::endl
            << "(Сравнений: " << (*it)->GetComparisons()
            << ", Перестановок: " << (*it)->GetSwaps() << ")" << std::endl;
    }
    std::cout << "Успешно сохранено в " << path << std::endl;
}
