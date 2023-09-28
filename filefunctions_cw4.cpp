#include <filesystem>
#include <fstream>
#include "input.h"
#include <iostream>
#include "cw4_functions.h"


bool IsDataCorrectCW4(std::ifstream& file) //The function checks if the data loaded from the file is valid
{
    std::string test_string{};
    if (file.eof())
    {
        std::cout << "Файл пуст!";
        return false;
    }

    return true;
}

std::string CheckFileCW4()
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
        else if (!IsDataCorrectCW4(file))
        {
            std::cout << "Данные некорректны!" << std::endl;
            file.close();
        }
        else
            isLoaded = true;
    } while (!isLoaded);

    std::cout << "Файл открыт!" << std::endl;
    file.close();

    return path;
}

void GetTextFromFile(std::string& text, std::string& path)
{
    std::ifstream file(path);
    std::string input{};

    while (!file.eof())
    {
        GetLine(file, input, CW4_INPUT, FILE_INPUT);
        text += (input);
        if (!file.eof())
            text += '\n';
    }

    std::cout << "Текст загружен!" << std::endl;
    file.close();
}

void SaveToFile(const std::string& restoredText, const std::string& modifiedText, int save_choice)
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
    } while (!isOpened);


    if (save_choice == SAVE_RESTORED)
        file << restoredText;

    else if (save_choice == SAVE_MODIFIED)
        file << modifiedText;

    std::cout << "Успешно сохранено в " << path << std::endl;
}
