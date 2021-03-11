#ifndef CREATURE_H
#define CREATURE_H

#include <iostream>

#include <string>

#include <string.h>

#include "being.h"

using namespace std;

class Creature:public Being{
public:
    Creature();

    Creature(string name, int life, int strength, int intelligence, string natural, int disquiet);

    virtual ~Creature();
    friend ostream& operator<<(ostream& out, Creature const& creature);
    
protected:
    string natural;
    int disquiet;
};

#endif