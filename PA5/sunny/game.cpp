#include <iostream>
#include <string>
#include "game.h"
#include <fstream>
#include <vector>
using namespace std;


Game::Game(){
    this->numOfPlayers = 0;
    this-> remainingLetters = "aaaaaaaaabbccddddeeeeeeeeeeeeffggghhiiiiiiiiijkllllmmnnnnnnooooooooppqrrrrrrssssttttttuuuuvvwwxyyz"; //Blanks?
    this->allLetters = "aaaaaaaaabbccddddeeeeeeeeeeeeffggghhiiiiiiiiijkllllmmnnnnnnooooooooppqrrrrrrssssttttttuuuuvvwwxyyz"; //Blanks?
    this->allowedWords = loadWords();
}

Game::Game(int numOfPlayers){
    this->numOfPlayers = numOfPlayers;
    this-> remainingLetters = "aaaaaaaaabbccddddeeeeeeeeeeeeffggghhiiiiiiiiijkllllmmnnnnnnooooooooppqrrrrrrssssttttttuuuuvvwwxyyz"; //Blanks?
    this->allLetters = "aaaaaaaaabbccddddeeeeeeeeeeeeffggghhiiiiiiiiijkllllmmnnnnnnooooooooppqrrrrrrssssttttttuuuuvvwwxyyz"; //Blanks?
    this->allowedWords = loadWords();
}

Game::Game(int numOfPlayers, string remainingLetters){
    this->numOfPlayers = numOfPlayers;
    this->remainingLetters = remainingLetters;
    this->allLetters = "aaaaaaaaabbccddddeeeeeeeeeeeeffggghhiiiiiiiiijkllllmmnnnnnnooooooooppqrrrrrrssssttttttuuuuvvwwxyyz"; //Blanks?
    this->allowedWords = loadWords();
}

vector<string> Game::loadWords(){
    vector<string> words;
    ifstream wordstream;
    wordstream.open("dictionary.txt");

    while (!wordstream.eof()){
        string line;
        wordstream >> line;
        words.push_back(line);
    }

    wordstream.close();
    return words;
}

bool Game::validWordCheck(string word, char playersHand[7]){
    for (int i = 0; i < word.length(); i++){
        bool found = false;

        for (int j = 0; j < 7; j++){
            if (word[i] == toupper(playersHand[j])) {
                found = true;
                break;
            }
        }

        if (!found) {
            return false;
        }
    }

    if (find(this->allowedWords.begin(), this->allowedWords.end(), word) != this->allowedWords.end()){
        return true;
    }
    return false;
}


Game::~Game(){

}

ostream& operator<<(ostream& out, const Game *game){
    out << "Number of players: " << game->numOfPlayers << "\nNumber of remaining letters: " << game->remainingLetters.length();
    return out;
}