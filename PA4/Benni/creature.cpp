#include <iostream>

#include <string>

#include <string.h>

#include "h/creature.h"

using namespace std;


Creature::Creature() : Being() {
    this->natural = rand() % 2;
    this->disquiet = rand() % 11;
}

Creature::Creature(string name, string type, int life, int strength, int intelligence, bool natural, int disquiet, int traumatism) : Being (name, type, life, strength, intelligence) {
    this->natural = natural;
    this->disquiet = disquiet;
    if (this->type == "Eldritch Horror"){
        this->traumatism = traumatism;
    }
    else{
        this->traumatism = -1;
    }
}

Creature::~Creature() {
    delete &natural;
    delete &disquiet;
    delete &traumatism;
}

ostream& operator<<(ostream& out, const Creature *creature) {
    out << "Name: " << creature->name << endl
        << "Type: " << creature->type << endl
        << "Life: " << creature->life << endl
        << "Strength: " << creature->strength << endl
        << "Intelligence: " << creature->intelligence << endl
        << "Natural: " << creature->natural << endl
        << "Disquiet: " << creature->disquiet << endl;
        if (creature->type == "Eldritch horror"){
            out << "Traumatism: " << creature->traumatism << endl;
        }
    return out;
};