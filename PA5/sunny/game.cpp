#include <iostream>
#include <string>
#include "game.h"
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


Game::Game(){
    this->numOfPlayers = 0;
    this->remainingLetters = "aaaaaaaaabbccddddeeeeeeeeeeeeffggghhiiiiiiiiijkllllmmnnnnnnooooooooppqrrrrrrssssttttttuuuuvvwwxyyz"; //Blanks?
    this->allLetters = "aaaaaaaaabbccddddeeeeeeeeeeeeffggghhiiiiiiiiijkllllmmnnnnnnooooooooppqrrrrrrssssttttttuuuuvvwwxyyz"; //Blanks?
    this->allowedWords = loadWords();
    this->highScores = getHighScores();
}

/* Game::Game(int numOfPlayers){
    this->numOfPlayers = numOfPlayers;
    this-> remainingLetters = "aaaaaaaaabbccddddeeeeeeeeeeeeffggghhiiiiiiiiijkllllmmnnnnnnooooooooppqrrrrrrssssttttttuuuuvvwwxyyz"; //Blanks?
    this->allLetters = "aaaaaaaaabbccddddeeeeeeeeeeeeffggghhiiiiiiiiijkllllmmnnnnnnooooooooppqrrrrrrssssttttttuuuuvvwwxyyz"; //Blanks?
    this->allowedWords = loadWords();
    this->highScores = getHighScores();
}

Game::Game(int numOfPlayers, string remainingLetters, char board[15][15]){
    this->numOfPlayers = numOfPlayers;
    this->remainingLetters = remainingLetters;
    this->allLetters = "aaaaaaaaabbccddddeeeeeeeeeeeeffggghhiiiiiiiiijkllllmmnnnnnnooooooooppqrrrrrrssssttttttuuuuvvwwxyyz"; //Blanks?
    this->allowedWords = loadWords();
    this->highScores = getHighScores();
} */

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

bool Game::fitsOnBoard(int colnum, int rownum, bool direction, string word){
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

void Game::modifyBoard(int colnum, int rownum, bool direction, string word){   //Direction is true for horizontal and false for vertical.
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

priority_queue<pair<int, string> > Game::getHighScores(){
    priority_queue<pair<int, string> > highScores;
    string playerName;
    string playSco;
    int playerScore;
    ifstream highstream;
    bool stillName = true;

    highstream.open("highscores.txt");
    while (!highstream.eof()){
        string line;
        highstream >> line;
        if (!line.empty()){
            for (int i = 0; i < line.length(); i++){
                if (line[i] == ':'){
                    stillName = false;
                }
                else if (stillName){
                    playerName += line[i];
                }
                else {
                    playSco += line[i];
                }
            }
        }
        if (!playSco.empty()){
            playerScore = stoi(playSco);
            highScores.push(make_pair(playerScore, playerName));
        }
        stillName = true;
        playerName = playSco = "";
    }
    highstream.close();

    return highScores;
}

void Game::writeHighScores(){
    int top;
    if (highScores.size() <= 4){
        top = this->highScores.size() - 1;
    }
    else{
        top = 5;
    }

    ofstream highstream;
    highstream.open("highscores.txt");

    for (int i = 0; i < (top); i++){
        string pname = this->highScores.top().second;
        int pscore = this->highScores.top().first;
        highstream << pname << ":" << pscore << endl;
        this->highScores.pop();
    }
    
    highstream.close();
}

void Game::addtoHighScores(int score, string name) {
    this->highScores.push(make_pair(score, name));
}

Game::~Game(){
    delete &allowedWords;
    delete &remainingLetters;
    delete &numOfPlayers;
    delete &allLetters;
    delete &highScores;
}

ostream& operator<<(ostream& out, const Game *game){
    out << "Number of players: " << game->numOfPlayers << "\nNumber of remaining letters: " << game->remainingLetters.length();
    return out;
}