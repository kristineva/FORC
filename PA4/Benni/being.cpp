#include <iostream>

#include <string>

#include <string.h>

#include "being.h"

using namespace std;


Being::Being(){
        this->name = "";
        this->life = rand() % 11;
        this->strength = rand() % 11;
        this->intelligence = rand() % 11;
    };
    
Being::Being(string name, int life, int strength, int intelligence){
        this->name = name;
        this->life = life;
        this->strength = strength;
        this->intelligence = intelligence;
    };