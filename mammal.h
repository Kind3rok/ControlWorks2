#ifndef MAMMAL_H
#define MAMMAL_H
#include <iostream>
#include <string>
#include <vector>


class Mammal
{
protected:
    std::string _wayOfEating{}, _habitat{};
    double _weight{};

public:
    virtual void Show() const = 0; 
    void SetHabitat();
    void SetHabitatFromFile(std::istream& input);
    void SetWayOfEating();
    void SetWayOfEatingFromFile(std::istream& input);
    void SetWeight();
    void SetWeightFromFile(std::istream& input);

    std::string GetHabitat()  { return _habitat; };
    std::string GetWayOfEating()  { return _wayOfEating; };
    double GetWeight()  { return _weight; };

    virtual ~Mammal() = default;
};

#endif
