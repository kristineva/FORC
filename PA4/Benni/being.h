#ifndef BEING_H
#define BEING_H

#include <string>

#include <string.h>

class Being{
public:
    Being();
    Being(string name, int life, int strength, int intelligence);
protected:
    string name;
    int life;
    int strength;
    int intelligence;
};

#endif