#include <iostream>

#include <string>

#include <string.h>

#include "person.h"

using namespace std;

class Investigator:public Person{
public:
    Investigator();

    Investigator(string name, string type, int life, int strength, int intelligence, string gender, int fear, int terror);

    virtual ~Investigator();

    friend ostream& operator<<(ostream& out, const Investigator *investigator);

private:
    int terror;
};