#ifndef PLAYER_H
#define PLAYER_H

#include <string>

using namespace std;

class Player{
public:
    Player();
    Player(string name);
    Player(string name, char hand[7], int points);

    int getRandomIndex(int numOfRemainLett);
    string newHand(string remainingLetters);
    string newLetters(string remainingLetters, string lettersUsed);
    void calculatePoints(string word);

    virtual ~Player();

    friend ostream& operator<<(ostream& out, const Player *player);

    string name;
    char hand[7];
    int points;
};

#endif