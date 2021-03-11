#ifndef PERSON_H
#define PERSON_H

#include <iostream>

#include <string>

#include <string.h>

#include <random>

#include <chrono>

#include "being.h"

using namespace std;

class Person : public Being{
public:
    Person();

    Person(string name, string type, int life, int strength, int intelligence, string gender, int fear);
    
    virtual ~Person();
    
    friend ostream& operator<<(ostream& out, const Person *person);
protected:
    string gender;
    int fear;
private:
};

#endif