#include "predator.h"
#include "input.h"
#include <iomanip>


void Predator::Show(void) const
{
    std::cout
        << "************************************************" << std::endl
        << "| ������ �������: " << _wayOfEating << std::endl
        << "| ���: " << std::fixed << std::setprecision(2) << _weight << " ��" << std::endl
        << "| ����� ��������: " << _habitat << std::endl
        << "| ���: " << _gender << std::endl
        << "| �������� ������������: " << std::fixed << std::setprecision(2) << _movementSpeed << " ��/�" << std::endl
        << "************************************************" << std::endl;
}

void Predator::SetGender(void)
{
    std::cout << "������� ���: ";
    GetLine(std::cin, _gender, WITHOUT_DIGITS, MANUAL_INPUT);
}

void Predator::SetGenderFromFile(std::istream& input)
{
    std::getline(input, _gender);
}

void Predator::SetMovementSpeed()
{
    std::cout << "������� �������� ������������: ";
    _movementSpeed = GetPosDouble();
}

void Predator::SetMovementSpeedFromFile(std::istream& input)
{
    input >> _movementSpeed; input.get();
}
