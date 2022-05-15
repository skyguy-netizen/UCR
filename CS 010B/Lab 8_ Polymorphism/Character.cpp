#include "Character.h"
#include <iostream>

using namespace std;

Character::Character(HeroType type, const string &name, double health, double attackStrength) : type(type), name(name), health(health), attackStrength(attackStrength){};

HeroType Character::getType() const
{
    return this->type;
}

const string &Character::getName() const
{
    return name;
}

int Character::getHealth() const
{
    return health;
}

void Character::damage(double d)
{
    health = health - d;
    cout << name << " takes " << d << " damage." << endl;
}

bool Character::isAlive() const
{
    return (health > 0);
}