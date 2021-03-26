#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    int choice;
    int numOfPlayers;
    char players[4][20];
    int points[4][1];
    char board[15][15];
    char allLetters[100] = {
    'a','a','a','a','a','a','a','a','b','b',
    'c','d','d','d','d','d','e','e','e','e',
    'e','e','e','f','f','g','g','g','h','h',
    'i','i','i','i','i','j','k','k','k','l',
    'l','l','l','l','m','m','m','n','n','n',              // letters same as in real scrabble board game
    'n','n','n','o','o','o','o','o','p','p',
    'q','q','q','r','r','r','r','r','s','s',
    's','s','s','s','s','s','t','t','t','t',
    't','t','t','t','u','u','u','v','v','w',
    'w','x','x','y','y','z','z','z','i','a'
    };

    while (true){
        cout << "Hello! Welcome to a fun game of Scrabble!\nTo start a new game, choose 1\nTo quit, choose 2\nYour choice: ";
        cin >> choice;
        if (choice == 1) {
            cout << "How many are playing? (2/3/4)\nYour choice: ";
            cin >> numOfPlayers;
            for (int i = 0; i < numOfPlayers; i++){
                cout << "Name of player: " << endl;
                cin >> players[i];
                
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