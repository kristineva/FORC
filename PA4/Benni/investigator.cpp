#include <iostream>

#include <string>

#include <string.h>

#include "h/investigator.h"

using namespace std;


Investigator::Investigator() : Person() { 
    this->terror = rand() % 4;
}

Investigator::Investigator(string name, string type, int life, int strength, int intelligence, string gender, int fear, int terror) : Person(name, type, life, strength, intelligence, gender, fear) {
    this->terror = terror;
}

Investigator::~Investigator() {
    delete &terror;
}

ostream& operator<<(ostream& out, const Investigator *investigator) {
    out << "Name: " << investigator->name << endl
        << "Type: " << investigator->type << endl
        << "Life: " << investigator->life << endl
        << "Strength: " << investigator->strength << endl
        << "Intelligence: " << investigator->intelligence << endl
        << "Gender: " << investigator->gender << endl
        << "Terror: " << investigator->terror << endl;
    return out;
};