#ifndef PREDATOR_H
#define PREDATOR_H
#include "mammal.h"


class Predator : public Mammal // ???
{
private:
    std::string _gender{};
    double _movementSpeed{};


public:
    void Show() const override;

    void SetGender();
    void SetGenderFromFile(std::istream& input);
    void SetMovementSpeed();
    void SetMovementSpeedFromFile(std::istream& input);

    double GetMovementSpeed() { return _movementSpeed; };
    std::string GetGender() { return _gender; };
    
    ~Predator() = default;
};

#endif