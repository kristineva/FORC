#include <iostream>

#include <string>

#include <string.h>

#include "investigator.h"

using namespace std;


Investigator::Investigator() : Person(){
        this->terror = rand() % 4;
    }

Investigator::Investigator(string name, int life, int strength, int intelligence, string gender, int fear, int terror) : Person(name, life, strength, intelligence, gender, fear){
        this->terror = terror;
    }