#ifndef CW1_FUNCTIONS_H
#define CW1_FUNCTIONS_H

#include "flight.h"

bool AllocateArray(Flight* flights, int amount);
void ShowFlight(Flight* flights, int amount);
void FillFlight(Flight* flights, int amount);
void SearchByDestination(Flight* List, Flight* ansFlights, int amount, int isTest);
void SearchByDay(Flight* List, Flight* ansFlights, int amount, int isTest);
void SearchByDayAndTime(Flight* List, Flight* ansFlights, int amount, int isTest);
bool IsListEmpty(Flight* flights, int amount);

#endif