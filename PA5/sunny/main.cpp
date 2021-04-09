#include <iostream>
#include <cstdlib>
#include <random>
#include <string>
#include <vector>
#include <fstream>
#include <queue>
#include "player.h"
#include "game.h"
using namespace std;

int main() {
    int numOfPlayers;
    Player players[4];
    string name;
    string word;
    char again;
    bool first = true;
    priority_queue<pair<int, string> > highScores;
    int choice;

    cout << "\nHello! Welcome to a fun game of Scrabble!";

    while (true){
        cout << "\n(1) New game\n(2) List of highscores\nUse any other key to quit.\nYour choice: ";
        cin >> choice;
        if (choice == 1){
            while (true){
                cout << "\nHow many are playing? (2/3/4)\nYour choice: ";
                cin >> numOfPlayers;
                Game game = Game(numOfPlayers);
                highScores = game.getHighScores();
                for (int i = 0; i < numOfPlayers; i++){
                    cout << "\nName of player: ";
                    cin >> name;
                    players[i].name = name;
                    game.remainingLetters = players[i].newHand(game.remainingLetters);
                }
                while (game.remainingLetters.length() != 0){
                    for (int i = 0; i < numOfPlayers; i++){
                        game.displayBoard();
                        cout << "\n" << players[i].name << ", it's your turn" << endl;
                        

                        cout << "\nFind a word from your letters.\nYour letters are:\n";
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
                                cout << word << " is not a valid word. Try again or, if you find no valid words, enter 'q' for\na new set of letters on the next turn.";
                                                    
                            }
                            else{
                                int row;
                                int col;
                                char direction;
                                bool dir;

                                while (true){
                                    if (first){
                                        cout << "You are placing the first word on the board. Make sure it lands on the middle square (row 8, column 8)\n";
                                    }
                                    cout << "In which column do you want to place this word?\nYour choice: ";
                                    cin >> col;
                                    cout << "In which row do you want to place this word?\nYour choice: ";
                                    cin >> row;
                                    cout << "Should the word be horizontal or vertical? (h/v)\n Your choice: ";
                                    cin >> direction;
                                    

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
                            
                                if (direction == 'h'){
                                    dir = true;
                                }
                                else{
                                    dir = false;
                                }
                            
                                game.modifyBoard(col, row, dir, word);   
                                players[i].calculatePoints(word);
                                game.remainingLetters = players[i].newLetters(game.remainingLetters, word);
                                
                                cout << players[i].name << "'s total points are: " << players[i].points << endl;
                                break;
                            }
                        }
                    }
                }
                
                for (int i = 0; i < numOfPlayers; i++){
                    cout << players[i].name << ", your total points are: " << players[i].points << endl << endl;
                    highScores.push(make_pair(players[i].points, players[i].name));
                }

                game.writeHighScores(highScores);
            }
        }
        else if (choice == 2){
            cout << "\nHIGH SCORES:\n\nNAME:POINTS\n";
            int counter = 1;
            fstream high;
            high.open("highscores.txt");

            while (!high.eof()){
                string line;
                high >> line;
                cout << counter++ << ":  " << line << endl;
            }

            high.close();
        }
        else{
            break;
        }
    }
}