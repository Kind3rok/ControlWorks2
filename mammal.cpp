#include "mammal.h"
#include "input.h"
#include <vector>


void Mammal::SetHabitat()
{
	std::cout << "¬ведите среду обитани€: ";
	GetLine(std::cin, _habitat, WITHOUT_DIGITS, MANUAL_INPUT);
}

void Mammal::SetHabitatFromFile(std::istream& input)
{
	std::getline(input, _habitat);
}

void Mammal::SetWayOfEating()
{
	std::cout << "¬ведите способ питани€: ";
	GetLine(std::cin, _wayOfEating, WITHOUT_DIGITS, MANUAL_INPUT);
}

void Mammal::SetWayOfEatingFromFile(std::istream& input)
{
	std::getline(input, _wayOfEating);
}

void Mammal::SetWeight()
{
	std::cout << "¬ведите вес: ";
	_weight = GetPosDouble();
}

void Mammal::SetWeightFromFile(std::istream& input)
{
	input >> _weight; input.get();
}

