#include <iostream>
#include <cstdlib>
#include <random>
#include <fstream>
#include <string>
#include <vector>
#include "player.h"
#include "game.h"
using namespace std;

void makeBoard () {
    int gridSize = 15;
    int cellSize = 4;
    int total = gridSize * cellSize;
    string c;
    string direction = "horizontal";
    int count = 0;
    int vertCount = 1;
    cout << "\n";
    cout << "     ";
    for (int k = 1; k < gridSize + 1; k++) {
        if (to_string(k).length() == 2) {
            cout << " " << " " << " " << k << " " << " " << " ";
        } else {
            cout << " " << " " << " " << k << " " << " " << " " << " ";
        }
    }

    cout << "\n";
    cout << "   ";
    for (int i = 0; i < total + 1; i++) {
        for (int j = 0; j < total + 1; j++) {
            if (i % cellSize == 0 || j % cellSize == 0) {
                if (direction == "horizontal") {
                    c = " _";
                    
                } else {
                    c = " |";
                }
                
            } else {
                c = "  ";
            }
            cout << c;
        }
        count++;
        cout << endl;
        if (count == cellSize) {
            direction = "horizontal";
            count = 0;
            cout << "   ";
        } else {
            if (vertCount != 16 && count == 2) {
                if (to_string(vertCount).length() == 2) {
                    cout << " " << vertCount;
                } else {
                    cout << " " << vertCount << " ";
                }
                vertCount++;
            } else {
                cout << "   ";
            }
            direction = "vertical";
        }
        
    }
    cout << "\n";
}
int main() {
    int numOfPlayers;
    Player players[4];
    string name;
    string word;
    string lineString;
    char again;

    cout << "\nHello! Welcome to a fun game of Scrabble!\n";
    
    ifstream f("rules.txt");

    if (f.is_open()) {
        cout << f.rdbuf();
    }

    while (true){
        cout << "\nHow many are playing? (2/3/4)\nYour choice: ";
        cin >> numOfPlayers;
        Game game = Game(numOfPlayers);
        for (int i = 0; i < numOfPlayers; i++){
            cout << "\nName of player: ";
            cin >> name;
            players[i].name = name;
            game.remainingLetters = players[i].newHand(game.remainingLetters);
        }
        makeBoard();
        while (game.remainingLetters.length() != 0){
            for (int i = 0; i < numOfPlayers; i++){
                cout << "\n" << players[i].name << ", it's your turn\nFind a word from your letters.\nYour letters are:\n" << endl;
                for (int j = 0; j < 7; j++){
                    cout << players[i].hand[j] << " ";
                }
                while(true){
                    cout << endl << "\nEnter your word: ";  //Finna út hvernig við látum hann setja það inn á borðið á réttan stað...
                    cin >> word;
                    if (word == "q"){
                        game.remainingLetters = players[i].newHand(game.remainingLetters);
                        break;
                    } else if (word == "/r") {
                        ifstream f("rules.txt");

                        if (f.is_open()) {
                            cout << f.rdbuf();
                        }
                    }

                    string upperWord = word;
                    for (int i = 0; i < word.size(); i++){
                        upperWord[i] = toupper(upperWord[i]);
                    }
                    
                    // bæta við að /r sé "valid word" þvi það eru reglurnar
                    if (!game.validWordCheck(upperWord, players[i].hand)){
                        cout << word << " is not a valid word. Try again or, if you find no valid words, enter 'q' for\na new set of letters on the next turn.";
                        
                    }
                    else{
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
        }

        cout << "Play again? (y/n): ";
        cin >> again;
        if (again != 'y'){
            break;
        }
    }
}