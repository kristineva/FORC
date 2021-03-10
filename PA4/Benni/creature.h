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

    Creature(string name, int life, int strength, int intelligence, bool natural, int disquiet);

    void print();
protected:
    bool natural;
    int disquiet;
};

#endif