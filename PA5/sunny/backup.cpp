#include <iostream>
#include <cstdlib>
#include <random>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

vector<string> loadWords(){
    vector<string> words;
    ifstream wordstream;
    wordstream.open("dictionary.txt");

    while (!wordstream.eof()){
        string line;
        wordstream >> line;
        words.push_back(line);
    }
    return words;
}

char giveRandomLetter(string remainingLetters){
    int num;
    num = rand() % ((sizeof remainingLetters) + 1);
    return remainingLetters[num];
}

string giveHand(string remainingLetters, char hand[7]){
    int num;
    for (int i = 0; i < 8; i++){

        hand[i] = giveRandomLetter(remainingLetters);
        remainingLetters.erase(num, 1);
    }
    return remainingLetters;
}

bool checkIfValidWord(string word, vector<string> validWords){
    if (find(validWords.begin(), validWords.end(), word) != validWords.end()){
        return true;
    }
    return false;
}

string giveNewLetters(string remainingLetters, char hand[7], string lettersUsed){
    for (int i = 0; i < 8; i++){
        if (lettersUsed.find(hand[i]) != string::npos){
            lettersUsed.erase(lettersUsed.find(hand[i]));

        }
    }
}

int main() {
    int choice;
    int numOfPlayers;
    char players[4][20];
    int points[4][1];
    char hand[4][7];
    char board[15][15];
    string remainingLetters = "aaaaaaaabbdddddeeeeeeeffggghhiiiiijkkklllllmmmnnnnnnoooooppqqqrrrrrssssssssttttttttuuuvvwwxxyyzzzia";
    vector<string> allowedWords;
    int counter = 0;
    allowedWords = loadWords();
    string word;
    
    while (true){
        cout << "Hello! Welcome to a fun game of Scrabble!\nTo start a new game, choose 1\nTo quit, choose 2\nYour choice: ";
        cin >> choice;
        if (choice == 1) {
            cout << "How many are playing? (2/3/4)\nYour choice: ";
            cin >> numOfPlayers;
            for (int i = 0; i < numOfPlayers; i++){
                cout << "Name of player: " << endl;
                cin >> players[i];
                remainingLetters = giveHand(remainingLetters, hand[i]);
            }
            // CLEAR SCREEN
            while (remainingLetters.size() != 0){
                for (int i = 0; i < numOfPlayers; i++){
                    cout << players[i] << ", it's your turn\nYour letters are: ";
                    for (int j = 0; j < 8; j++){
                        cout << hand[i][j];
                    }
                    while(true){
                        cout << endl << "Enter your word: ";  //Finna út hvernig við látum hann setja það inn á borðið á réttan stað...
                        cin >> word;
                        if (word == "q"){
                            break;
                        }

                        for (int i = 0; i < word.size(); i++){
                            word[i] = toupper(word[i]);
                        }

                        if (!checkIfValidWord(word, allowedWords)){
                            cout << word << "is not a valid word. Try again, or, if you find no valid words press 'q'" << endl;

                        }
                        else{
                            remainingLetters = giveNewLetters(remainingLetters, hand[i], word);
                            break;
                        }
                    }
                }
                
            }
        }
        else if (choice != 2) {
            cout << choice << " is not an option. Please try again.\n";
        }
        else {
            break;
        }
    }

}