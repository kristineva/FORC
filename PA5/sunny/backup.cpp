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

    wordstream.close();
    return words;
}

int giveRandomIndex(string remainingLetters){
    srand(chrono::system_clock::to_time_t(chrono::system_clock::now()));
    return rand() % (remainingLetters.length());
}

string giveHand(string remainingLetters, char hand[7]){
    int num;
    if (remainingLetters.length() < 7){
        for (int i = 0; i < remainingLetters.length(); i++){
            hand[i] = remainingLetters[i];
            remainingLetters.erase(i, 1);
        }
    }
    else{
        for (int i = 0; i < 7; i++){
            num = giveRandomIndex(remainingLetters);
            hand[i] = remainingLetters[num];
            remainingLetters.erase(num, 1);
        }
    }   
    return remainingLetters;
}

bool checkIfValidWord(string word, vector<string> validWords, char hand[7]){
    
    for (int i = 0; i < word.length(); i++){
        bool found = false;

        for (int j = 0; j < 7; j++){
            if (word[i] == toupper(hand[j])) {
                found = true;
                break;
            }
        }

        if (!found) {
            return false;
        }
    }

    if (find(validWords.begin(), validWords.end(), word) != validWords.end()){
        return true;
    }
    return false;
}

string giveNewLetters(string remainingLetters, char hand[7], string lettersUsed){
    int num;
    string strhand = string(hand);
    char new_hand[7];

    if (remainingLetters.length() < 7){
        for (int i = 0; i < remainingLetters.length(); i++){
            hand[i] = remainingLetters[i];
            remainingLetters.erase(i, 1);
        }
    }
    else{
        for (int i = 0; i < 7; i++){
            new_hand[i] = hand[i];
        }

        int begin = (lettersUsed.length() - 1);
        for (int i = begin; i >= 0; i--){                    //riwhqia      //riah
            for (int j = 6; j >=0; j--){
                if (lettersUsed[i] == hand[j]){
                    int pos = strhand.find(hand[j]);
                    if (pos != string::npos){
                        num = giveRandomIndex(remainingLetters);
                        new_hand[j] = remainingLetters[num];
                        remainingLetters.erase(num, 1);
                        strhand.erase(pos, 1);
                        break;
                    }
                }
            }
        }
        for (int i = 0; i < 7; i++){
                hand[i] = new_hand[i];
        }
    }
    return remainingLetters;

}

void calculatePoints(string word, int points[4], int place){
    for (int i = 0; i < word.length(); i++){
        if ((word[i] == 'a') || (word[i] == 'e') || (word[i] == 'i') || (word[i] == 'o') || (word[i] == 'u') || (word[i] == 'l') || (word[i] == 'n') || (word[i] == 's') || (word[i] == 't') || (word[i] == 'r')){
            points[place] = points[place] + 1;
        }

        else if ((word[i] == 'd') || (word[i] == 'g')){
            points[place] = points[place] + 2;
        }

        else if ((word[i] == 'b') || (word[i] == 'c') || (word[i] == 'm') || (word[i] == 'p')){
            points[place] = points[place] + 3;
        }

        else if ((word[i] == 'f') || (word[i] == 'h') || (word[i] == 'v') || (word[i] == 'w') || (word[i] == 'y')){
            points[place] = points[place] + 4;
        }

        else if (word[i] == 'k'){
            points[place] = points[place] + 6;
        }

        else if ((word[i] == 'j') || (word[i] == 'x')){
            points[place] = points[place] + 8;
        }

        else if ((word[i] == 'q') || (word[i] == 'z')){
            points[place] = points[place] + 10;
        }
    }
}

int main() {
    int choice;
    int numOfPlayers;
    char agin;
    char players[4][20];
    int points[4];
    char hand[4][7];
    char board[15][15];
    string allLetters = "aaaaaaaaabbccddddeeeeeeeeeeeeffggghhiiiiiiiiijkllllmmnnnnnnooooooooppqrrrrrrssssttttttuuuuvvwwxyyz"; //Blanks?
    string remainingLetters = "aaaaaaaaabbccddddeeeeeeeeeeeeffggghhiiiiiiiiijkllllmmnnnnnnooooooooppqrrrrrrssssttttttuuuuvvwwxyyz"; //Blanks?
    vector<string> allowedWords;
    int counter = 0;
    allowedWords = loadWords();
    string word;
    
    cout << "Hello! Welcome to a fun game of Scrabble!\n";
    cout << "To start a new game, choose 1\nTo quit, choose 2\nYour choice: ";
    cin >> choice;
    while (true){
        
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
                    for (int j = 0; j < 7; j++){
                        cout << hand[i][j];
                    }
                    while(true){
                        cout << endl << "Enter your word: ";  //Finna út hvernig við látum hann setja það inn á borðið á réttan stað...
                        cin >> word;
                        if (word == "q"){
                            remainingLetters = giveHand(remainingLetters, hand[i]);
                            break;
                        }

                        string upperWord = word;
                        for (int i = 0; i < word.size(); i++){
                            upperWord[i] = toupper(upperWord[i]);
                        }

                        if (!checkIfValidWord(upperWord, allowedWords, hand[i])){
                            cout << word << " is not a valid word. Try again, or, if you find no valid words press 'q' for a new set of letters." << endl;
                            
                        }
                        else{
                            calculatePoints(word, points, i);
                            remainingLetters = giveNewLetters(remainingLetters, hand[i], word);
                            
                            
                            cout << "Points: " << points[i] << endl;
                            break;
                        }
                    }
                }
                
            }
            for (int i = 0; i < numOfPlayers; i++){
                cout << players[i] << ", your total points are: " << points[i] << endl;
            }
            cout << "Play again? (y/n): ";
            cin >> agin;
            if (agin != 'y'){
                break;
            }
            else{
                remainingLetters = allLetters;
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