#include <filesystem>
#include <fstream>
#include "predator.h"
#include "input.h"


bool IsDataCorrectCW2(std::ifstream& file) //The function checks if the data loaded from the file is valid
{
    std::string test_string{};
    double test_double{};

    if (!file.eof())
    {
        GetLine(file, test_string, WITHOUT_DIGITS, FILE_INPUT); //way of eating
        if (test_string.empty())
        {
            std::cout << "Ошибка считывания способа питания!" << std::endl;
            return false;
        }

        file >> test_double; //weight
        if (test_double > DBL_WRONG)
        {
            std::cout << "Ошибка считывания веса, превышено максимальное значение!" << std::endl;
            return false;
        }
        if (file.fail())
        {
            std::cout << "Ошибка считывания веса!" << std::endl;
            return false;
        };
        file.get();
        GetLine(file, test_string, WITHOUT_DIGITS, FILE_INPUT); //habitat
        if (test_string.empty())
        {
            std::cout << test_string << std::endl;
            std::cout << "Ошибка считывания среды обитания!" << std::endl;
            return false;
        }

        GetLine(file, test_string, WITHOUT_DIGITS, FILE_INPUT); //gender
        if (test_string.empty())
        {
            std::cout << "Ошибка считывания пола!" << std::endl;
            return false;
        }

        file >> test_double; //movement speed
        if (test_double > DBL_WRONG)
        {
            std::cout << "Ошибка считывания скорости передвижения, превышено максимальное значение!" << std::endl;
            return false;
        }
        if (file.fail())
        {
            std::cout << "Ошибка считывания скорости передвижения!" << std::endl;
            return false;
        };

        while (file.get() != EOF); //to clean up possible residual information
    }
    else
        std::cout << "Файл пуст!" << std::endl;

    file.seekg(0, std::ios::beg);  //If everything went well, then return the pointer to the beginning of the file

    return true;
}

std::string CheckFileCW2(void)
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
        else if (!IsDataCorrectCW2(file))
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

void GetPredatorFromFile(std::vector<Mammal*>& predator, int amount, std::string path = CheckFileCW2())
{
    std::ifstream file(path);

    for (int i = 0; i < amount && !file.eof(); i++)
    {
        Predator* new_predator = new Predator;
        new_predator->SetWayOfEatingFromFile(file);
        new_predator->SetWeightFromFile(file);
        new_predator->SetHabitatFromFile(file);
        new_predator->SetGenderFromFile(file);
        new_predator->SetMovementSpeedFromFile(file);

        predator.push_back(new_predator);
    }

    std::cout << "Список загружен!" << std::endl;

    file.close();
}

void SaveToFile(std::vector<Mammal*>& predator) // ???
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
        std::getline(std::cin, path);

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

        file.open(path, std::ios::trunc); // ???

        if (!file)
            std::cout << "Ошибка открытия файла!" << std::endl;
        else
            isOpened = true;
    } 
    while (!isOpened);

    std::string outputWayOfEating{}, outputHabitat{}, outputGender{};
    double outputWeight{}, outputMovementSpeed{};

    for (std::vector<Mammal*>::iterator it = predator.begin(); it != predator.end(); it++)
    {
        outputWayOfEating = (*it)->GetWayOfEating();
        outputWeight = (*it)->GetWeight();
        outputHabitat = (*it)->GetHabitat();
        outputGender = dynamic_cast<Predator*>(*it)->GetGender();
        outputMovementSpeed = dynamic_cast<Predator*>(*it)->GetMovementSpeed();

        if (it != predator.begin())
            file << std::endl;
        file << outputWayOfEating << std::endl;
        file << outputWeight << std::endl;
        file << outputHabitat << std::endl;
        file << outputGender << std::endl;
        file << outputMovementSpeed;
    }
    std::cout << "Успешно сохранено в " << path << std::endl;
}

int CountStringsCW2(std::string path)
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