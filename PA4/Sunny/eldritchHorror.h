#ifndef ELDRITCHHORROR_H
#define ELDRITCHHORROR_H

#include <iostream>

#include <string>

#include <string.h>

#include "creature.h"

using namespace std;

class EldritchHorror:Creature{
public:
    EldritchHorror();

    EldritchHorror(string name, int life, int strength, int intelligence, int traumatism);
private:
    int traumatism;
};

#endif