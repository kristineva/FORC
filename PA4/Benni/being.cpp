#include <iostream>
#include <string>
#include <string.h>
#include "h/being.h"

using namespace std;


Being::Being() {
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

Being::~Being() {
    delete &name;
    delete &life;
    delete &strength;
    delete &intelligence;
};

ostream& operator<<(ostream& out, Being const& being) {
    out << "Name: " << being.name;
    out << "Life: " << being.life;
    return out;
};