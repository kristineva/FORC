#include <iostream>

#include <string>

#include <string.h>

#include "person.cpp"

using namespace std;

class Investigator:Person{
public:
    Investigator() : Person(){
        this->terror = rand() % 4;
    }

    Investigator(int life, int strength, int intelligence, string gender, int fear, int terror) : Person(life, strength, intelligence, gender, fear){
        this->terror = terror;
    }
private:
    int terror;
};