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

bool Game::fitsOnBoard(int colnum, int rownum, bool direction, string word){        //rows  //2 //13 //True // 4
    if ((colnum > 15) || (rownum > 15)){
        return false;
    }
    else if ((direction) && (((colnum - 1) + word.length()) > 15)){
        return false;
    }
    else if ((!direction) && (((rownum - 1) + word.length()) > 15)){
        return false;
    }
    return true;
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
    }
}

void Game::modifyBoard(int colnum, int rownum, bool direction, string word){   //Direction is true for right and false for down.
    for (int i = 0; i < word.length(); i++) {
        if (direction){
            this->board[colnum+i-1][rownum-1] = word[i];
        }
        else {
            this->board[colnum-1][rownum+i-1] = word[i];
        }
    }

}

void Game::displayBoard(){
    cout << endl;
    for (int i = 1; i < 16; i++){
        if (i==1){
            cout << "   " << i << " ";
        }
        else if (i < 10){
            cout << " " << i << " ";
        }
        else{
            cout << " " <<i;
        }
        
    }
    cout << endl;
    for (int col = 0; col < 15; col++){
        if ((col + 1) < 10){
            cout << " " << (col + 1);
        }
        else{
            cout << (col + 1);
        }
        for (int row = 0; row < 15; row++){
            cout << "[" << this->board[row][col] << "]";
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