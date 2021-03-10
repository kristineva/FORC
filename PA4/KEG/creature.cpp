#include <iostream>

#include <string>

#include <string.h>

#include "h/creature.h"

using namespace std;


Creature::Creature() : Being(){
    this->natural = rand() % 2;
    this->disquiet = rand() % 11;
    }

Creature::Creature(string name, int life, int strength, int intelligence, bool natural, int disquiet) : Being (name, life, strength, intelligence){
    this->natural = natural;
    this->disquiet = disquiet;
    }

Creature::~Creature(){
    delete &natural;
    delete &disquiet;
}

ostream& operator<<(ostream& out, Creature const& creature){
    out << "Name: " << creature.name;
    out << "Life: " << creature.life;
    return out;
}

/* void Creature::print(){
    string nat;
    if (natural == true){
        nat = "Yes";
    }
    else{
        nat = "No";
    }

    cout << "Name: " << name 
         << "\nLife: " << life 
         << "\nStrength: " << strength 
         << "\nIntelligence: " << intelligence 
         << "\nNatural: " << nat
         << "\nDisquiet: " << disquiet;
}*/ 