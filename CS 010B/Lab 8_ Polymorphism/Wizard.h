#include "Character.h"
#ifndef WIZARD_H
#define WIZARD_H

class Wizard : public Character
{
private:
    int rank;

public:
    Wizard(const string &name, double health, double attackStrength, int rank);
    int getRank() const { return rank; }
    void attack(Character &victim);
};

#endif