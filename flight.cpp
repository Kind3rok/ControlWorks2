#include "flight.h"
#include "input.h"

void Flight::SetDestination(void)
{
    std::cout << "������� ����� ����������: ";
    GetLine(std::cin, _destination, WITH_DIGITS, MANUAL_INPUT);
}

void Flight::SetDestinationFromFile(std::istream& input)
{
    std::getline(input, _destination);
}
void Flight::SetTime(void)
{
    InputTime(_time.hours, _time.minutes);
}
void Flight::SetTimeFromFile(std::istream& input)
{
    std::getline(input, _time.hours, ':');
    std::getline(input, _time.minutes);
}
void Flight::SetNumberFlight(void)
{
    std::cout << "������� ����� �����: ";
    _number_flight = GetPosInt();
}

void Flight::SetTypeFlight(void)
{
    std::cout << "������� ��� ��������: ";
    GetLine(std::cin, _type_flight, WITH_DIGITS, MANUAL_INPUT);
}

void Flight::SetDay(void)
{
    std::cout << "������� ���� ������: ";
    GetLine(std::cin, _day, WITHOUT_DIGITS, MANUAL_INPUT);
}

void Flight::SetNumberFlightFromFile(std::istream& input)
{
    input >> _number_flight;  input.get();
}

void Flight::SetTypeFlightFromFile(std::istream& input)
{
    std::getline(input, _type_flight);
}

void Flight::SetDayFromFile(std::istream& input)
{
    std::getline(input, _day);
}

Time Flight::GetTime()
{
    return _time;
};

std::string Flight::GetDestination()
{
    return _destination;
};

int Flight::GetNumberFlight()
{
    return _number_flight;
};

std::string Flight::GetTypeFlight()
{
    return _type_flight;
};

std::string Flight::GetDay()
{
    return _day;
}

void Flight::ShowFlight()
{
    std::cout
        << std::endl
        << "************************************************" << std::endl
        << "| ����� ����������: " << _destination << std::endl
        << "| ����� �����: " << _number_flight << std::endl
        << "| ��� ��������: " << _type_flight << std::endl
        << "| ����� ������: " << _time.hours << ':' << _time.minutes  << std::endl
        << "| ���� ������: " << _day << std::endl
        << "************************************************" << std::endl
        << std::endl;
}
bool Flight::IsEmpty()
{
    return false;
}
;


