#ifndef GAME_H
#define GAME_H

#include <string>

#include <string.h>

using namespace std;

class Game {
public:
    Game();

    Game(string allLetters, string remainingLetters, string usersWord, vector<string> allowedWords);

    virtual ~Game();

    friend ostream& operator<<(ostream& out, const Game *game);

    string allLetters;
    string remainingLetters;
    string usersWord;
    vector<string> allowedWords;
};

#endif