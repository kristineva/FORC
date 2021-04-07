#ifndef GAME_H
#define GAME_H

#include <string>

#include <vector>

using namespace std;

class Game {
public:
    Game();

    Game(int numOfPlayers);

    Game(int numOfPlayers, string remainingLetters);

    vector<string> loadWords();
    
    bool validWordCheck(string word, char playersHand[7]);


    virtual ~Game();

    friend ostream& operator<<(ostream& out, const Game *game);

    int numOfPlayers;
    string allLetters;
    string remainingLetters;
    string usersWord;
    vector<string> allowedWords;
};

#endif