#include <iostream>

#include <string>

#include <string.h>

#include "being.cpp"

using namespace std;

class Creature:Being{
public:
    Creature() : Being(){
        this->natural = rand() % 2;
        this->disquiet = rand() % 11;
    }

    Creature(int life, int strength, int intelligence, bool natural, int disquiet) : Being (life, strength, intelligence){
        this->natural = natural;
        this->disquiet = disquiet;
    }
protected:
    bool natural;
    int disquiet;
};