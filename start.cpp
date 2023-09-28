#include "filefunctions_cw1.h"
#include "filefunctions_cw2.h"
#include "filefunctions_cw3.h"
#include "filefunctions_cw4.h"
#include "input.h"
#include "cw_info.h"
#include "cw1_functions.h"
#include "tests_cw1.h"
#include "cw2_functions.h"
#include "tests_cw2.h"
#include "cw3_functions.h"
#include "tests_cw3.h"
#include "cw4_functions.h"
#include "tests_cw4.h"



void StartCW1(void)
{
    int user_choice{};
    do
    {
        int flights_amount{};
        std::string file_path{};
        Flight* flights = nullptr;
        std::string temp;
        Flight* ansFlights = nullptr;
        UnitTestCW1 tests{};
        std::string destination;
       
        InfoCW1();
        ShowMainMenuCW1();
        switch (user_choice = GetKey(FILE_INPUT, MODUL_TESTS))
        {
            case FILE_INPUT:
            {
                do
                {
                    file_path = CheckFile();
                    flights_amount = (CountStrings(file_path) / 5);

                    std::cout << "Загружено рейсов: " << flights_amount << std::endl;
                    if (AllocateArray(flights, flights_amount))
                        flights = new Flight[flights_amount];
                    else
                        std::cout << "Произошла ошибка. попробуйте ещё раз!" << std::endl;
                }
                while (!AllocateArray(flights, flights_amount));

                GetListFromFile(flights, flights_amount, file_path);
                break;
            }

            case MANUAL_INPUT:
            {
                do
                {
                    std::cout << "Введите число рейсов: ";
                    flights_amount = GetPosInt();
                    if (AllocateArray(flights, flights_amount))
                        flights = new Flight [flights_amount];
                    else
                        std::cout << "Произошла ошибка. попробуйте ещё раз!" << std::endl;
                }
                while (!AllocateArray(flights, flights_amount));

                FillFlight(flights, flights_amount);
                break;
            }

            case MODUL_TESTS:
                tests.RunAllTests();
                break;

            case QUIT: 
                break;
        }

        while (user_choice != QUIT)
        {
            ShowMenuCW1();
            switch (user_choice = GetKey(SEARCHbyDestination, SAVECW1))
            {
            case SEARCHbyDestination:
                SearchByDestination(flights, ansFlights, flights_amount, MANUAL_INPUT);
                break;

            case SEARCHbyDay:
                SearchByDay(flights, ansFlights, flights_amount, MANUAL_INPUT);
                break;

            case SEARCHbyDayAndTime:
                SearchByDayAndTime(flights, ansFlights, flights_amount, MANUAL_INPUT);
                break;
            
            case SHOW_ALL:
                ShowFlight(flights, flights_amount);
                break;

            case SAVECW1:
                if (!IsListEmpty(flights, flights_amount))
                    SaveToFile(flights, flights_amount);
                else
                    std::cout << "Список пуст!" << std::endl;
                break;

            case QUIT:
                break;
            }
        }
        if (flights != nullptr)
        {
            delete[] flights;
            flights = nullptr;
        }
            
        std::cout << "1 - Запустить эту КР ещё раз, 2 - Выбрать другую КР, ESC - Завершить работу программы." << std::endl;
        user_choice = GetKey(YES, NO);
        if (user_choice == QUIT)
            exit(EXIT_SUCCESS);
    } 
    while (user_choice != NO);
}

void StartCW2(void)
{
    int user_choice{};
    do
    {
        std::vector<Mammal*> predator{};
        int predator_amount{};
        std::string file_path{};
        UnitTestCW2 tests{};

        InfoCW2();
        ShowMainMenuCW2();
        switch (user_choice = GetKey(FILE_INPUT, MODUL_TESTS))
        {
            case FILE_INPUT:
                file_path = CheckFileCW2();
                predator_amount = (CountStringsCW2(file_path) / 5);
                std::cout << "Загружено хищников: " << predator_amount << std::endl;
                GetPredatorFromFile(predator, predator_amount, file_path);
                break;

            case MANUAL_INPUT:
                std::cout << "Введите число хищников: ";
                predator_amount = GetPosInt();
                FillPredator(predator, predator_amount);
                break;

            case MODUL_TESTS:
                tests.RunAllTests();
                break;

            case QUIT:
                break;
        }

        while (user_choice != QUIT)
        {
            ShowMenuCW2();
            switch (user_choice = GetKey(SHOW, SAVECW2))
            {
                case SHOW:
                    if (!(predator.size() < 1))
                        ShowPredator(predator);
                    else
                        std::cout << "Список пуст!" << std::endl;
                    break;
                case SAVECW2:
                    if (!(predator.size() < 1))
                        SaveToFile(predator);
                    else
                        std::cout << "Список пуст!" << std::endl;
                    break;

                case QUIT:
                    break;
            }
        }
        for (std::vector<Mammal*>::const_iterator it = predator.begin(); it != predator.end(); it++)
        {
            delete *it;
        }
        std::cout << "1 - Запустить эту КР ещё раз, 2 - Выбрать другую КР, ESC - Завершить работу программы." << std::endl;
        user_choice = GetKey(YES, NO);
        if (user_choice == QUIT)
            exit(EXIT_SUCCESS);
    } 
    while (user_choice != NO);
}

void StartCW3(void)
{
    int user_choice{};
    do
    {
        std::vector<ISort*> sorts{};
        std::vector<Matrix*> matrices{};

        BubbleSort* bubble_sort = new BubbleSort;
        sorts.push_back(bubble_sort);

        SelectionSort* selection_sort = new SelectionSort;
        sorts.push_back(selection_sort);

        InsertionSort* insertion_sort = new InsertionSort;
        sorts.push_back(insertion_sort);

        ShellSort* shell_sort = new ShellSort;
        sorts.push_back(shell_sort);

        QuickSort* quick_sort = new QuickSort;
        sorts.push_back(quick_sort);

        std::vector<std::vector<int>> matrix{}, rows_to_save{}, columns_to_save{};
        int rows{}, columns{};
        std::string file_path{};
        UnitTestCW3 tests{};

        InfoCW3();
        ShowMainMenuCW3();

        switch (user_choice = GetKey(FILE_INPUT, RANDOM_INPUT))
        {
        case FILE_INPUT:
            file_path = CheckFileCW3();
            GetMatrixFromFile(matrix, rows, columns, file_path);
            break;

        case MANUAL_INPUT:
            std::cout << "Введите количество строк: ";
            rows = GetPosInt();
            std::cout << "Введите количество столбцов: ";
            columns = GetPosInt();

            FillMatrix(matrix, rows, columns);
            break;

        case MODUL_TESTS:
            tests.RunAllTests();
            break;

        case RANDOM_INPUT:
            std::cout << "Введите количество строк: ";
            rows = GetPosInt();
            std::cout << "Введите количество столбцов: ";
            columns = GetPosInt();

            FillMatrixRandomly(matrix, rows, columns);
            break;

        case QUIT:
            break;
        }
        GoSort(matrix, rows, columns, sorts, matrices);

        while (user_choice != QUIT && user_choice != MODUL_TESTS)
        {
            ShowMenuCW3();
            switch (user_choice = GetKey(SHOW, SAVECW3))
            {
            case SHOW:
                ShowResults(matrix, rows, columns, sorts, matrices);
                break;

            case SAVECW3:
                SaveToFile(sorts, matrices, matrix, rows, columns);
                break;

            case QUIT:
                break;
            }
        }

        for (std::vector<Matrix*>::iterator it = matrices.begin(); it != matrices.end(); it++)
        {
            delete* it;
        }
        delete bubble_sort;
        delete selection_sort;
        delete insertion_sort;
        delete shell_sort;
        delete quick_sort;

        std::cout << "1 - Запустить эту КР ещё раз, 2 - Выбрать другую КР, ESC - Завершить работу программы." << std::endl;
        user_choice = GetKey(YES, NO);
        if (user_choice == QUIT)
            exit(EXIT_SUCCESS);
    } 
    while (user_choice != NO);
}

void StartCW4(void)
{
    int user_choice{};
    do
    {
        std::string restoredText{}, modifiedText{}, text{}, file_path{};
        bool isSequenceSizeSetted = false, isLoopMenu = false, error = false;
        size_t sequence_size = 2;
        UnitTestCW4 tests{};

        InfoCW4();
        ShowMainMenuCW4();

        switch (user_choice = GetKey(FILE_INPUT, MODUL_TESTS))
        {
        case FILE_INPUT:
            isLoopMenu = true;
            file_path = CheckFileCW4();
            GetTextFromFile(text, file_path);
            break;

        case MANUAL_INPUT:
            isLoopMenu = true;
            InputText(text);
            break;

        case MODUL_TESTS:
            tests.RunAllTests();
            break;

        case QUIT:
            break;
        }

        while (isLoopMenu)
        {
            ShowMenuCW4();
            switch (user_choice = GetKey(ENTRY_LENGTH, SAVE_MODIFIED))
            {
            case ENTRY_LENGTH:
                SetSequenceSize(sequence_size);
                isSequenceSizeSetted = true;
                break;

            case SHOW_RESTORED:
                if (restoredText.empty())
                    StartRestore(text, restoredText, error);
                ShowRestored(restoredText);
                break;

            case SHOW_MODIFIED:
                if (!isSequenceSizeSetted)
                {
                    SetSequenceSize(sequence_size);
                    isSequenceSizeSetted = true;
                }
                RestoreText(text, error);
                if (!error)
                {
                    std::cout << "Размер подстроки взят со значением = " << sequence_size << std::endl;
                    StartModify(text, modifiedText, sequence_size);
                    ShowModified(modifiedText);
                }
                break;

            case SAVE_RESTORED:
                if (restoredText.empty())
                {
                    std::cout << "Сначала восстановите текст!" << std::endl;
                    break;
                }
                SaveToFile(restoredText, modifiedText, SAVE_RESTORED);
                break;

            case SAVE_MODIFIED:
                if (modifiedText.empty())
                {
                    std::cout << "Сначала модифицируйте текст!" << std::endl;
                    break;
                }
                SaveToFile(restoredText, modifiedText, SAVE_MODIFIED);
                break;

            case QUIT:
                isLoopMenu = false;
                break;
            }
        }

        std::cout << "1 - Запустить эту КР ещё раз, 2 - Выбрать другую КР, ESC - Завершить работу программы." << std::endl;
        user_choice = GetKey(YES, NO);
        if (user_choice == QUIT)
            exit(EXIT_SUCCESS); 
    } 
    while (user_choice != NO);
}
