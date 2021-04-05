#ifndef PLAYER_H
#define PLAYER_H

#include <string>

#include <string.h>

using namespace std;

class Player {
public:
    Player();

    Player(string name, char[7] hand, int points);

    virtual ~Player();

    friend ostream& operator<<(ostream& out, const Player *player);

    string name;
    int points;
};

#endif