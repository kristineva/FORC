#ifndef CREATURE_H
#define CREATURE_H

#include <iostream>

#include <string>

#include <string.h>

#include "being.h"

using namespace std;

class Creature:public Being {
public:
    Creature();

    Creature(string name, string type, int life, int strength, int intelligence, bool natural, int disquiet, int traumatism);

    virtual ~Creature();

    friend ostream& operator<<(ostream& out, const Creature *creature);
    
protected:
    string natural;
    int disquiet;
    int traumatism;
};

#endif