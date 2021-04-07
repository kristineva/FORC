#include <iostream>
using namespace std;

int main(){
    int rownum = 3;
    int colum = 4;

    for (int col = 0; col < 15; col++){
        for (int row = 0; row < 15; row++){
            if ((row == (rownum-1)) && (col == (colum-1))){
                cout << "[" << "H" << "]";
            }
            else{
                cout << "[ ]";
            }
        }
        cout << endl;
    }
}