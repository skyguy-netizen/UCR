#include "Character.h"
#include "Wizard.h"
#include <cstdlib>
#include <iostream>

using namespace std;

Wizard::Wizard(const string &name, double health, double attackStrength, int rank) : Character(WIZARD, name, health, attackStrength), rank(rank) {}

void Wizard::attack(Character &victim)
{
    if (victim.getType() == WIZARD)
    {
        // cout << "Attacking wizard rank: " << rank << endl;
        // cout << "Divisor: " << static_cast<double>(rank) / (dynamic_cast<Wizard &>(victim).getRank()) << endl;
        double d = attackStrength * (static_cast<double>(rank) / (dynamic_cast<Wizard &>(victim).getRank()));
        // cout << "Damage done: " << d << endl;
        //  cout << "Wizard damage: " << d << endl;
        cout << "Wizard " << name << " attacks " << victim.getName() << " --- POOF!!" << endl;
        victim.damage(d);
    }
    else
    {
        cout << "Wizard " << name << " attacks " << victim.getName() << " --- POOF!!" << endl;
        victim.damage(attackStrength);
    }
}
