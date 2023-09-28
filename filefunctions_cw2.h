#ifndef FILEFUNCTIONS_CW2_H
#define FILEFUNCTIONS_CW2_H
#include "predator.h"
#include "input.h"

bool IsDataCorrectCW2(std::ifstream& file);

std::string CheckFileCW2();

void GetPredatorFromFile(std::vector<Mammal*>& predator, int amount, std::string path = CheckFileCW2());

void SaveToFile(std::vector<Mammal*>& predator);

int CountStringsCW2(std::string path);


#endif
