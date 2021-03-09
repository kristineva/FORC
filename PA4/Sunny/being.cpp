#include <iostream>

#include <string>

#include <string.h>

using namespace std;

class Being{
public:
    Being(){
        this->life = rand() % 11;
        this->strength = rand() % 11;
        this->intelligence = rand() % 11;
    };
    Being(int life, int strength, int intelligence){
        this->life = life;
        this->strength = strength;
        this->intelligence = intelligence;
    };
protected:
    int life;
    int strength;
    int intelligence;
};