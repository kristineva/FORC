#include <iostream>
#include <cstdlib>
#include <random>
#include <fstream>
#include <string>
#include <vector>
#include "player.h"
#include "game.h"
using namespace std;

int main() {
    int numOfPlayers;
    Player players[4];
    string name;
    string word;
    char again;

    cout << "Hello! Welcome to a fun game of Scrabble!\n";
    

    while (true){
        cout << "How many are playing? (2/3/4)\nYour choice:  ";
        cin >> numOfPlayers;
        Game game = Game(numOfPlayers);
        for (int i = 0; i < numOfPlayers; i++){
            cout << "Name of player: ";
            cin >> name;
            players[i].name = name;
            game.remainingLetters = players[i].newHand(game.remainingLetters);
        }
        while (game.remainingLetters.length() != 0){
            for (int i = 0; i < numOfPlayers; i++){
                cout << players[i].name << ", it's your turn\nYour letters are: ";
                for (int j = 0; j < 7; j++){
                    cout << players[i].hand[j];
                }
                while(true){
                    cout << endl << "Enter your word: ";  //Finna út hvernig við látum hann setja það inn á borðið á réttan stað...
                    cin >> word;
                    if (word == "q"){
                        game.remainingLetters = players[i].newHand(game.remainingLetters);
                        break;
                    }

                    string upperWord = word;
                    for (int i = 0; i < word.size(); i++){
                        upperWord[i] = toupper(upperWord[i]);
                    }

                    if (!game.validWordCheck(upperWord, players[i].hand)){
                        cout << word << " is not a valid word. Try again, or, if you find no valid words press 'q' for a new set of letters." << endl;
                        
                    }
                    else{
                        players[i].calculatePoints(word);
                        game.remainingLetters = players[i].newLetters(game.remainingLetters, word);
                        
                        
                        cout << players[i].name << "'s total points are" << players[i].points << endl;
                        break;
                    }
                }
            }
        }
        for (int i = 0; i < numOfPlayers; i++){
            cout << players[i].name << ", your total points are: " << players[i].points << endl;
        }

        cout << "Play again? (y/n): ";
        cin >> again;
        if (again != 'y'){
            break;
        }
    }
}