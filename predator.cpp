#include "predator.h"
#include "input.h"
#include <iomanip>


void Predator::Show(void) const
{
    std::cout
        << "************************************************" << std::endl
        << "| Способ питания: " << _wayOfEating << std::endl
        << "| Вес: " << std::fixed << std::setprecision(2) << _weight << " кг" << std::endl
        << "| Среда обитания: " << _habitat << std::endl
        << "| Пол: " << _gender << std::endl
        << "| Скорость передвижения: " << std::fixed << std::setprecision(2) << _movementSpeed << " км/ч" << std::endl
        << "************************************************" << std::endl;
}

void Predator::SetGender(void)
{
    std::cout << "Введите пол: ";
    GetLine(std::cin, _gender, WITHOUT_DIGITS, MANUAL_INPUT);
}

void Predator::SetGenderFromFile(std::istream& input)
{
    std::getline(input, _gender);
}

void Predator::SetMovementSpeed()
{
    std::cout << "Введите скорость передвижения: ";
    _movementSpeed = GetPosDouble();
}

void Predator::SetMovementSpeedFromFile(std::istream& input)
{
    input >> _movementSpeed; input.get();
}
