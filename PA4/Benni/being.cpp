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
    
Being::Being(string name, string type, int life, int strength, int intelligence) {
        this->name = name;
        this->type = type;
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

ostream& operator<<(ostream& out, const Being *being) {
    out << "Name: " << being->name << endl
        << "Type: " << being->type << endl
        << "Life: " << being->life << endl
        << "Strength: " << being->strength << endl
        << "Intelligence: " << being->intelligence << endl;
    return out;
};