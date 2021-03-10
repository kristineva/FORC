#ifndef BEING_H
#define BEING_H

#include <string>

#include <string.h>

using namespace std;

class Being{
public:
    Being();
    Being(string name, int life, int strength, int intelligence);
    virtual ~Being();
protected:
    string name;
    int life;
    int strength;
    int intelligence;
};

#endif