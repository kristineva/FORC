#include <iostream>

#include <string>

#include <string.h>

#include "creature.cpp"

using namespace std;

class EldritchHorror:Creature{
public:
    EldritchHorror() : Creature(){
        this->disquiet = 10;
        this->natural = false;
        this->traumatism = rand() % 4;
    }

    EldritchHorror(int life, int strength, int intelligence, int traumatism) : Creature(life, strength, intelligence, natural = false, disquiet = 10){
        this->traumatism = traumatism;
    }
private:
    int traumatism;
};