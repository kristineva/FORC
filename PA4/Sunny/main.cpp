#include <iostream>
#include <random>
#include <chrono>
#include <string.h>
#include <string>

#include "being.cpp"
#include "creature.cpp"
#include "eldritchHorror.cpp"
#include "investigator.cpp"
#include "person.cpp"

using namespace std;

int main(){
    srand(chrono::system_clock::to_time_t(chrono::system_clock::now()));
    return 0;
}
