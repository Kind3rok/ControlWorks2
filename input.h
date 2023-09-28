#ifndef INPUT_H
#define INPUT_H

#include <conio.h>
#include <string>
#include <vector>


constexpr auto KEY_ESC = 0x1B;
constexpr auto KEY_1 = 0x31;
constexpr auto KEY_2 = 0x32;
constexpr auto KEY_3 = 0x33;
constexpr auto KEY_4 = 0x34;
constexpr auto KEY_5 = 0x35;
constexpr auto KEY_6 = 0x36;
constexpr auto KEY_7 = 0x37;
constexpr auto KEY_8 = 0x38;
const double DBL_WRONG = 100000000000000000;

enum InputMenu
{
    FILE_INPUT = KEY_1,
    MANUAL_INPUT = KEY_2,
    MODUL_TESTS = KEY_3,
    RANDOM_INPUT = KEY_4
};

enum MenuCW
{
    CW1 = KEY_1,
    CW2 = KEY_2,
    CW3 = KEY_3,
    CW4 = KEY_4,
    QUIT = KEY_ESC
};

enum BoolMenu
{
    YES = KEY_1,
    NO = KEY_2
};

enum BoolInput
{
    WITHOUT_DIGITS,
    WITH_DIGITS,
    ONLY_DIGITS,
    ALMOST_ALL_DIGITS,
    CW4_INPUT
};

enum MainMenuCW1
{
    SEARCHbyDestination = KEY_1,
    SEARCHbyDay = KEY_2,
    SEARCHbyDayAndTime = KEY_3,
    SHOW_ALL = KEY_4,
    SAVECW1 = KEY_5
};

enum MainMenuCW2
{
    SHOW = KEY_1,
    SAVECW2 = KEY_2
};

enum MainMenuCW3
{
    SAVECW3 = KEY_2
};

enum MainMenuCW4
{
    ENTRY_LENGTH = KEY_1,
    SHOW_RESTORED = KEY_2,
    SHOW_MODIFIED = KEY_3,
    SAVE_RESTORED = KEY_4,
    SAVE_MODIFIED = KEY_5
};

enum SORTS
{
    BUBBLE_SORT,
    SELECTION_SORT,
    INSERTION_SORT,
    SHELL_SORT,
    QUICK_SORT
};

int GetKey(int key_min, int key_max);

int GetPosInt();
int GetInt();
int GetRandInt(int lowBound, int upBound);
size_t GetSequenceSize();
double GetDouble();
double GetPosDouble();

bool GetBool();

std::string GetLine(std::istream& _Input, std::string& line, int num_exists, int isInput);
void InputTime(std::string& hours, std::string& minutes);


#endif