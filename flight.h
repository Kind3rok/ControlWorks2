#ifndef FLIGHT_H
#define FLIGHT_H

#include <string>
#include <iostream>

struct Time
{
	std::string hours{};
	std::string minutes{};
};
class Flight
{
private:
	std::string _destination{};
	int _number_flight{};
	Time _time{};
	std::string _type_flight{};
	std::string _day{};

public:
	void SetDestination();
	void SetDestinationFromFile(std::istream& input);
	void SetNumberFlight();
	void SetNumberFlightFromFile(std::istream& input);
	void SetTypeFlight();
	void SetTypeFlightFromFile(std::istream& input);
	void SetDay();
	void SetDayFromFile(std::istream& input);
	void SetTime();
	void SetTimeFromFile(std::istream& input);
	Time GetTime();
	std::string GetDestination();
	int GetNumberFlight();
	std::string GetTypeFlight();
	std::string GetDay();
	void ShowFlight();
	bool IsEmpty();
};

#endif