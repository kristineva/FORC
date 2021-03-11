#include <iostream>

#include <string>

#include <string.h>

#include <random>

#include <chrono>

#include "h/person.h"

using namespace std;


Person::Person() : Being() {
        this->gender = "";
        this->fear = rand() % 11;
}

Person::Person(string name, string type, int life, int strength, int intelligence, string gender, int fear) : Being(name, type, life, strength, intelligence) {
        this->gender = gender;
        this->fear = fear;
}

Person::~Person(){
    delete &gender;
    delete &fear;
}

ostream& operator<<(ostream& out, const Person *person) {
    out << "Name: " << person->name << endl
        << "Type: " << person->type << endl
        << "Life: " << person->life << endl
        << "Strength: " << person->strength << endl
        << "Intelligence: " << person->intelligence << endl
        << "Gender: " << person->gender << endl
        << "Fear: " << person->fear << endl;
    return out;
};