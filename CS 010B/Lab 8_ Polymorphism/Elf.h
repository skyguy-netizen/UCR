#include "Character.h"

class Elf : public Character
{
private:
    string family;

public:
    Elf(const string &name, double health, double attackStrength, string family);
    void attack(Character &victim);
    string getFamily() const { return family; }
};