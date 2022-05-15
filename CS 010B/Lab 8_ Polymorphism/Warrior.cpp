#include "Warrior.h"
#include "Character.h"
#include <iostream>

using namespace std;

Warrior::Warrior(const string &name, double health, double attackStrength, string allegiance) : Character(WARRIOR, name, health, attackStrength), allegiance(allegiance) {}

void Warrior::attack(Character &victim)
{
    if (victim.getType() == WARRIOR && dynamic_cast<Warrior &>(victim).getAllegiance() == this->allegiance)
    {
        cout << "Warrior " << name << " does not attack Warrior " << victim.getName() << "." << endl;
        cout << "They share an allegiance with " << this->allegiance << "." << endl;
    }
    else
    {
        cout << "Warrior " << name << " attacks " << victim.getName() << " --- SLASH!!" << endl;
        double d = (health / MAX_HEALTH) * attackStrength;
        victim.damage(d);
    }
}