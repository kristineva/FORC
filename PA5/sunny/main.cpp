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

int main() {
    int choice;
    system("clear");
    cout << "\nHello! Welcome to a fun game of Scrabble!";

    while (true){
        system("clear");
        cout << "\n\n(1) New game\n(2) List of highscores\n(3) Rules\n\nUse any other key to quit.\n\nYour choice: ";
        cin >> choice;
        bool first = true;
        if (choice == 1){
            string str_numOfPlayers;
            Player players[4];
            Game game = Game();
            string name;
            string word;
            char again;
            priority_queue<pair<int, string> > highScores;
            system("clear");
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
                    
                        game.numOfPlayers = numOfPlayers;
                        highScores = game.getHighScores();
                        game.fillBoard();
                        game.remainingLetters = game.allLetters;
                        system("clear");
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
                                        string str_col;
                                        string str_row;

                                        while (true){

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

                                                }
                                                else { 
                                                    // convertible to int 
                                                    col = stoi(str_col);
                                                    while (true) {
                                                        cout << "\nIn which row do you want to place this word?\nYour choice: ";
                                                        cin >> str_row;
                                                        stringstream ssRow(str_row);

                                                        if ((ssRow >> j).fail()) { 
                                                            // not convertible to int 
                                                            cout << "\nRow value must be a number, try again.\n";

                                                        } 
                                                        else { 
                                                            // convertible to int 
                                                            row = stoi(str_row);
                                                            break;
                                                        } 
                                                    }
                                                    break;
                                                }
                                                
                                                
                                            }
                                            while (true){
                                                cout << "\nShould the word be placed across or down? (a/d)\nYour choice: ";
                                                cin >> direction;
                                                
                                                if (direction == 'a'){
                                                    dir = true;
                                                    break;
                                                }
                                                else if (direction == 'd'){
                                                    dir = false;
                                                    break;
                                                }
                                                else{
                                                    cout << "'" << direction << "' is not an option, try again.\n";
                                                }
                                            }
                    
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
                        cout << "\nEnter any key to go back to main menu: " << endl;
                        string cont;
                        cin >> cont;
                        game.writeHighScores(highScores);
                        break;
                    } else {
                        cout << "'" << numOfPlayers << "' is not an option, the options are 2, 3 or 4 players, try again.\n";
                    }
                }
            }
        }
        else if (choice == 2){
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
            string cont;
            cin >> cont;
            high.close();
        }
        else if (choice == 3){
            system("clear");
            cout << "\nRULES\n\nNAME:POINTS\n";
            ifstream file("rules.txt");

            if (file.is_open()) {
                cout << file.rdbuf();
            }

            cout << "\nEnter any key to go back to main menu: ";
            string cont;
            cin >> cont;
        }
        else {
            cout << "exit game";
            break;
        }
    }
}