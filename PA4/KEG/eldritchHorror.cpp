#include <iostream>

#include <string>

#include <string.h>

#include "h/eldritchHorror.h"
using namespace std;

EldritchHorror::EldritchHorror() : Creature(){
    this->disquiet = 10;
    this->natural = false;
    this->traumatism = rand() % 4;
    }

EldritchHorror::EldritchHorror(string name, int life, int strength, int intelligence, int traumatism) : Creature(name, life, strength, intelligence, false, 10){
    this->traumatism = traumatism;
    }

EldritchHorror::~EldritchHorror(){
    delete &traumatism;
}