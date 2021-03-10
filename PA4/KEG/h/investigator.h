#include <iostream>

#include <string>

#include <string.h>

#include "person.h"

using namespace std;

class Investigator:Person{
public:
    Investigator();

    Investigator(string name, int life, int strength, int intelligence, string gender, int fear, int terror);

    virtual ~Investigator();
private:
    int terror;
};