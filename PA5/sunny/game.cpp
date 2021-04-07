#include <iostream>
#include <string>
#include "game.h"
#include <fstream>
#include <vector>
using namespace std;


Game::Game(){
    this->numOfPlayers = 0;
    this->remainingLetters = "aaaaaaaaabbccddddeeeeeeeeeeeeffggghhiiiiiiiiijkllllmmnnnnnnooooooooppqrrrrrrssssttttttuuuuvvwwxyyz"; //Blanks?
    this->allLetters = "aaaaaaaaabbccddddeeeeeeeeeeeeffggghhiiiiiiiiijkllllmmnnnnnnooooooooppqrrrrrrssssttttttuuuuvvwwxyyz"; //Blanks?
    this->allowedWords = loadWords();
    fillBoard();
}

Game::Game(int numOfPlayers){
    this->numOfPlayers = numOfPlayers;
    this-> remainingLetters = "aaaaaaaaabbccddddeeeeeeeeeeeeffggghhiiiiiiiiijkllllmmnnnnnnooooooooppqrrrrrrssssttttttuuuuvvwwxyyz"; //Blanks?
    this->allLetters = "aaaaaaaaabbccddddeeeeeeeeeeeeffggghhiiiiiiiiijkllllmmnnnnnnooooooooppqrrrrrrssssttttttuuuuvvwwxyyz"; //Blanks?
    this->allowedWords = loadWords();
    fillBoard();
}

Game::Game(int numOfPlayers, string remainingLetters, char board[15][15]){
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

void Game::fillBoard(){
    for (int col = 0; col < 15; col++){
        for (int row = 0; row < 15; row++){
            this->board[col][row] = ' ';
        }
        cout << endl;
    }
}

void Game::modifyBoard(int colnum, int rownum, bool direction, string word){   //Direction is true for right and false for down.
    for (int i = 0; i < word.length(); i++) {
        if (direction){
            this->board[rownum+i-1][colnum-1] = word[i];
        }
        else {
            this->board[rownum-1][colnum+i-1] = word[i];
        }
    }

}

void Game::displayBoard(){
    cout << endl << endl;
    for (int col = 0; col < 15; col++){
        for (int row = 0; row < 15; row++){
            if (row == 4 && col == 5){
                cout << "[A]";
            }
            else{
                cout << "[" << this->board[row][col] << "]";
            }
            
        }
        cout << endl;
    }
}

Game::~Game(){
    delete &allowedWords;
    delete &remainingLetters;
}

ostream& operator<<(ostream& out, const Game *game){
    out << "Number of players: " << game->numOfPlayers << "\nNumber of remaining letters: " << game->remainingLetters.length();
    return out;
}