#include <iostream>

#include <string>

#include <string.h>

#include "creature.h"

using namespace std;


Creature::Creature() : Being(){
        this->natural = rand() % 2;
        this->disquiet = rand() % 11;
    }

Creature::Creature(string name, int life, int strength, int intelligence, bool natural, int disquiet) : Being (name, life, strength, intelligence){
        this->natural = natural;
        this->disquiet = disquiet;
    }

void Creature::print(){
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
}