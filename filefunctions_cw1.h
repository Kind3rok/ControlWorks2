#ifndef filefunctions_cw1_H
#define filefunctions_cw1_H

#include "flight.h"

bool IsDataCorrectCW1(std::ifstream& file);

std::string CheckFile(void);

void GetListFromFile(Flight *List, int amount, std::string path = CheckFile());

void SaveToFile(Flight *List, int amount);

int CountStrings(std::string path);


#endif
