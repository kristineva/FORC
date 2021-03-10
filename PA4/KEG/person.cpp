#include <iostream>

#include <string>

#include <string.h>

#include <random>

#include <chrono>

#include "person.h"

using namespace std;


Person::Person() : Being(){
        this->gender = "";
        this->fear = rand() % 11;
    }

Person::Person(string name, int life, int strength, int intelligence, string gender, int fear) : Being(name, life, strength, intelligence){
        this->gender = gender;
        this->fear = fear;
    }

void Person::print(){
    cout << "Name: " << name 
         << "\nLife: " << life 
         << "\nStrength: " << strength 
         << "\nIntelligence: " << intelligence 
         << "Gender: " << gender 
         << "Fear: " << fear;
}

Person::~Person(){
    delete &gender;
    delete &fear;
}