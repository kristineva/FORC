#include <iostream>
#include <string>
#include "player.h"
#include <random>
#include <chrono>

using namespace std;

Player::Player(){
    this->points = 0;
    this->name = "Undefined";
}

Player::Player(string name){
    this->name = name;
    this->points = 0;
}

Player::Player(string name, char hand[7], int points){
    this->name = name;
    this->points = points;
    for (int i = 0; i < 7; i++){
        this->hand[i] = hand[i];
    }
}

void Player::calculatePoints(string word){
    for (int i = 0; i < word.length(); i++){
        if ((word[i] == 'a') || (word[i] == 'e') || (word[i] == 'i') || (word[i] == 'o') || (word[i] == 'u') || (word[i] == 'l') || (word[i] == 'n') || (word[i] == 's') || (word[i] == 't') || (word[i] == 'r')){
            this->points += 1;
        }

        else if ((word[i] == 'd') || (word[i] == 'g')){
            this->points += 2;
        }

        else if ((word[i] == 'b') || (word[i] == 'c') || (word[i] == 'm') || (word[i] == 'p')){
            this->points += 3;
        }

        else if ((word[i] == 'f') || (word[i] == 'h') || (word[i] == 'v') || (word[i] == 'w') || (word[i] == 'y')){
            this->points += 4;
        }

        else if (word[i] == 'k'){
            this->points += 6;
        }

        else if ((word[i] == 'j') || (word[i] == 'x')){
            this->points += 8;
        }

        else if ((word[i] == 'q') || (word[i] == 'z')){
            this->points += 10;
        }
    }
}

int Player::getRandomIndex(int numOfRemainLett){
    srand(chrono::system_clock::to_time_t(chrono::system_clock::now()));
    return rand() % (numOfRemainLett);
}

string Player::newHand(string remainingLetters){
    int num;
    if (remainingLetters.length() < 7){
        for (int i = 0; i < remainingLetters.length(); i++){
            hand[i] = remainingLetters[i];
            remainingLetters.erase(i, 1);
        }
    }
    else{
        for (int i = 0; i < 7; i++){
            num = getRandomIndex(remainingLetters.length());
            hand[i] = remainingLetters[num];
            remainingLetters.erase(num, 1);
        }
    }   
    return remainingLetters;
}
string Player::newLetters(string remainingLetters, string lettersUsed){
    int num;
    string strhand = string(this->hand);
    char new_hand[7];

    if (remainingLetters.length() < 7){
        for (int i = 0; i < remainingLetters.length(); i++){
            hand[i] = remainingLetters[i];
            remainingLetters.erase(i, 1);
        }
    }
    else{
        for (int i = 0; i < 7; i++){
            new_hand[i] = this->hand[i];
        }

        int begin = (lettersUsed.length() - 1);
        for (int i = begin; i >= 0; i--){
            for (int j = 6; j >=0; j--){
                if (lettersUsed[i] == this->hand[j]){
                    int pos = strhand.find(this->hand[j]);
                    if (pos != string::npos){
                        num = getRandomIndex(remainingLetters.length());
                        new_hand[j] = remainingLetters[num];
                        remainingLetters.erase(num, 1);
                        strhand.erase(pos, 1);
                        break;
                    }
                }
            }
        }
        for (int i = 0; i < 7; i++){
                this->hand[i] = new_hand[i];
        }
    }
    return remainingLetters;
}


Player::~Player(){

}

ostream& operator<<(ostream& out, const Player *player){
    out << "heyyyy";
    return out;
}
