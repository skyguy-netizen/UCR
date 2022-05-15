#include "Elf.h"
#include "Character.h"
#include <iostream>

using namespace std;

Elf::Elf(const string &name, double health, double attackStrength, string family) : Character(ELF, name, health, attackStrength), family(family) {}

void Elf::attack(Character &victim)
{
    if (victim.getType() == ELF && dynamic_cast<Elf &>(victim).getFamily() == family)
    {
        cout << "Elf " << name << " does not attack Elf " << victim.getName() << "." << endl;
        cout << "They are both members of the " << family << " family." << endl;
    }
    else
    {
        cout << "Elf " << name << " shoots an arrow at " << victim.getName() << " --- TWANG!!" << endl;
        double d = (this->health / MAX_HEALTH) * this->attackStrength;
        victim.damage(d);
    }
}