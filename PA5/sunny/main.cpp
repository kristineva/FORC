#include <iostream>
#include <cstdlib>
#include <random>
#include <string>
#include <vector>
#include <fstream>
#include <queue>
#include "player.h"
#include "game.h"
#include <typeinfo>
#include <sstream>
using namespace std;

int getNumOfPlayers() {
    string str_numOfPlayers;
    while (true) {
        cout << "\nHow many are playing? (2/3/4)\n\nYour choice: ";
        cin >> str_numOfPlayers;

        stringstream ssNum(str_numOfPlayers); 
        int j;
        if ((ssNum >> j).fail()) { 
            // not convertible to int 
            cout << "'" << str_numOfPlayers << "' is not an option, the options are 2, 3 or 4 players, try again.\n";

        } else {
            int numOfPlayers = stoi(str_numOfPlayers);

            if ((numOfPlayers == 2) || (numOfPlayers == 3) || (numOfPlayers == 4)){
                return numOfPlayers;
                break;
            } else {
                cout << "'" << numOfPlayers << "' is not an option, the options are 2, 3 or 4 players, try again.\n";
            }
        }
    }
}

string getRules() {
    string cont;
    system("clear");
    cout << "\nRULES\n";
    ifstream file("rules.txt");

    if (file.is_open()) {
        cout << file.rdbuf();
    }

    cout << "\nEnter any key to go back to main menu: ";
    cin >> cont;
    return cont;
}

string printHighScores() {
    string cont;
    system("clear");
    cout << "\nHIGH SCORES\n\nNAME:POINTS\n";
    int counter = 1;
    fstream high;
    high.open("highscores.txt");

    while (!high.eof()){
        string line;
        high >> line;
        if (!line.empty()){
            cout << counter++ << ":  " << line << endl;
        }
    }
    cout << "\nEnter any key to go back to main menu: ";
    
    cin >> cont;
    high.close();
    return cont;
}

int getCol(bool first) {
    string str_col;
    while(true) {
        if (first){
            cout << "\nYou are placing the first word on the board.\nMake sure a letter in your word lands on the middle square (column 8, row 8)\n";
        }

        cout << "\nIn which column do you want to place this word?\nYour choice: ";
        cin >> str_col;

        stringstream ssCol(str_col); 
        int j;
        if ((ssCol >> j).fail()) { 
            // not convertible to int 
            cout << "\nColumn value must be a number, try again.\n";

        } else {
            return stoi(str_col);
        }
    }
}

int getRow() {
    string str_row;
    while (true) {
        cout << "\nIn which row do you want to place this word?\nYour choice: ";
        cin >> str_row;
        stringstream ssRow(str_row);
        int j;
        if ((ssRow >> j).fail()) { 
            // not convertible to int 
            cout << "\nRow value must be a number, try again.\n";

        } 
        else { 
            // convertible to int 
            return stoi(str_row);
        } 
    }
}

bool getDirection() {
    char direction;
    bool dir;
    while (true){
        cout << "\nShould the word be placed across or down? (a/d)\nYour choice: ";
        cin >> direction;
        
        if (direction == 'a'){
            dir = true;
            return dir;
        }
        else if (direction == 'd'){
            dir = false;
            return dir;
        }
        else{
            cout << "'" << direction << "' is not an option, try again.\n";
        }
    }
}


int main() {

    system("clear");
    cout << "\nHello! Welcome to a fun game of Scrabble!";

    while (true){
        string cont;
        int choice;
        system("clear");
        cout << "\n\n(1) New game\n(2) List of highscores\n(3) Rules\n\nUse any other key to quit.\n\nYour choice: ";
        cin >> choice;
        bool first = true;
        bool isGameFinished = false;
        int numOfPlayers;
        if (choice == 1){
            priority_queue<pair<int, string> > highScores;
            Game game = Game();
            while (!isGameFinished) {
                
                Player players[4];

                system("clear");
                numOfPlayers = getNumOfPlayers();
                game.numOfPlayers = numOfPlayers;

                
                highScores = game.getHighScores();
                game.fillBoard();
                game.remainingLetters = game.allLetters;
                system("clear");

                string name;
                for (int i = 0; i < numOfPlayers; i++){
                    while(true) {
                        cout << "\nName of player " << i+1 << ": ";
                        cin >> name;
                        bool happened = false;
                        for (int j = 0; j < i+1; j++){
                            if (players[j].name == name){
                                cout << "\nPlayers must have unique names, please select a different name: ";
                                happened = true;
                            }
                        }
                        if (!happened){
                            break;
                        }
                    }
                    players[i].name = name;
                    game.remainingLetters = players[i].newHand(game.remainingLetters);
                }
                while (game.remainingLetters.length() != 0){
                    for (int i = 0; i < numOfPlayers; i++){
                        system("clear");
                        game.displayBoard();
                        cout << "\n" << players[i].name << ", it's your turn" << endl;
                        

                        cout << "\nFind a word from your letters.\nIf you can't find a valid word, enter 'q' for a new set of letters on the next turn.\n\nYour letters are:\n";
                        for (int j = 0; j < 7; j++){
                            cout << players[i].hand[j] << " ";
                        }
                        while(true){
                            string word;
                            cout << endl << "\nEnter your word: ";
                            cin >> word;
                            if (word == "q"){
                                game.remainingLetters = players[i].newHand(game.remainingLetters);
                                break;
                            }

                            string upperWord = word;
                            for (int i = 0; i < word.size(); i++){
                                upperWord[i] = toupper(upperWord[i]);
                            }

                            if ((!game.validWordCheck(upperWord, players[i].hand))){
                                cout << word << " is not a valid word. Try again or, if you can't find a valid word, enter 'q' for\na new set of letters on the next turn.";
                                                    
                            }
                            else{
                                int row;
                                int col;
                                char direction;
                                bool dir;

                                while (true){
                                    col = getCol(first);
                                    row = getRow();
                                    dir = getDirection();
                                
            
                                    if (!game.fitsOnBoard(col, row, dir, word)){
                                        cout << "'" << word << "' does not fit on the board at that position. Try again." << endl;
                                    }
                                    else {
                                        if (first){
                                            if ((!((8-(word.length() + 1) <= row) && (row <= 8))) || (!((8 - (word.length() + 1 ) <= col) && (col <= 8)))){
                                                cout << "The word does not land on the middle square. Try again.\n";
                                            }
                                            else{
                                                first = false;
                                                break;
                                            }
                                        }
                                        else{
                                            break;
                                        }
                                    }
                                }
                            
                                game.modifyBoard(col, row, dir, word);   
                                players[i].calculatePoints(word);
                                game.remainingLetters = players[i].newLetters(game.remainingLetters, word);
                                
                                string next;
                                cout << "\nYour total points are: " << players[i].points << endl;
                                if (i == numOfPlayers - 1) {
                                    cout << "\nWhen the next player (" << players[0].name  <<" is ready for their turn, enter any key: ";
                                } else {
                                    cout << "\nWhen the next player (" << players[i+1].name  <<") is ready for their turn, enter any key: ";
                                }
                                cin >> next;
                                break;
                            }
                        }
                    }
                }
                for (int i = 0; i < numOfPlayers; i++){
                    cout << "\n" << players[i].name << ", your total points are: " << players[i].points << endl;
                    highScores.push(make_pair(players[i].points, players[i].name));
                }
                
                isGameFinished = true;
            
            }
            game.writeHighScores(highScores);
            cin >> cont;
            // break;
        }
        else if (choice == 2){
            cont = printHighScores();
        }
        else if (choice == 3){
            cont = getRules();
        }
        else {
            cout << "Exiting game...";
            break;
        }
    }
}