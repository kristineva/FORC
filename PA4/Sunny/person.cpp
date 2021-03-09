#include <iostream>

#include <string>

#include <string.h>

#include "being.cpp"

#include <random>

#include <chrono>

using namespace std;

class Person : public Being{
public:
    Person() : Being(){
        this->gender = "";
        this->fear = rand() % 11;
    }

    Person(int life, int strength, int intelligence, string gender, int fear) : Being(life, strength, intelligence){
        this->gender = gender;
        this->fear = fear;
    }
    
protected:
    string gender;
    int fear;
private:
};