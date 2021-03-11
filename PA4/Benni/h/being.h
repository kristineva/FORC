#ifndef BEING_H
#define BEING_H

#include <string>

#include <string.h>

using namespace std;

class Being {
public:
    Being();

    Being(string name, string type, int life, int strength, int intelligence);

    virtual ~Being();

    friend ostream& operator<<(ostream& out, const Being *being);

    string name;
    string type;
    int life;
    int strength;
    int intelligence;
};

#endif