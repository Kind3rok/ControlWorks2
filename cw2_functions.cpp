#include "input.h"
#include "filefunctions_cw2.h"
#include "predator.h"
#include <vector>
#include <iostream>


void FillPredator(std::vector<Mammal*>& predator, int amount)
{
    std::cout << std::endl;
    int Predator_id = 1;
    for (int i = 0; i < amount; i++, Predator_id++)
    {
        std::cout << "Заполните информацию о хищнике # " << Predator_id << std::endl;
        Predator* new_predator = new Predator;
        new_predator->SetWayOfEating();
        new_predator->SetWeight();
        new_predator->SetHabitat();
        new_predator->SetGender();
        new_predator->SetMovementSpeed();
        predator.push_back(new_predator);
    }
}


void ShowPredator(std::vector<Mammal*>& predator)
{
    int Predator_id = 1; // ???
    for (std::vector<Mammal*>::const_iterator it = predator.cbegin(); it != predator.cend(); it++, Predator_id++)
    {   
        std::cout << "Хищник # " << Predator_id << std::endl;
        (*it)->Show();
    }
}
