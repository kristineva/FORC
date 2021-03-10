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

    Person(string name, int life, int strength, int intelligence, string gender, int fear);
    
    virtual ~Person();
    
    void print();
protected:
    string gender;
    int fear;
private:
};

#endif