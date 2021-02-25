#include <iostream>

#include <fstream>

#include "trees.h"

#include <queue>

#include <string.h>

using namespace std;


int main(){

    priority_queue<DataClass, vector<DataClass>, greater<DataClass> > data_queue;
    Node *node = NULL;
    DataClass data = NULL;
    

    string lineString;
    string fileString;
    string uniqueString;

    int countChar;
    int checkChar;
    
    ifstream fin;
    fin.open("words.txt");

    while(!fin.eof()){
        fin >> lineString;
        fileString.append(lineString);
    }

    fin.close();
    
    for(int i = 0; i < fileString.length(); i++){
        checkChar = count(uniqueString.begin(), uniqueString.end(), fileString[i]);

        if (checkChar == 0){
            countChar = count(fileString.begin(), fileString.end(), fileString[i]);
            uniqueString.append(string(1,fileString[i]));
            data = DataClass(countChar, fileString[i]);
            
            data_queue.push(data);
            
        }
    }
    


    while(!data_queue.empty()){
        Node *left = new Node(data_queue.top());
        cout << "LEFT:  "<< data_queue.top() << endl;
        data_queue.pop();

        countChar = left->data.number;
        Node *right = NULL;

        if (!data_queue.empty()){
            Node *right = new Node(data_queue.top());
            cout << "RIGHT: " << data_queue.top() << endl;
            data_queue.pop();
            countChar += right->data.number;

            
        }
        node = new Node(DataClass(countChar), left, right);

        if (!data_queue.empty()){
            data_queue.push(node);
        }
    }



    HuffTree *huffman = NULL;
    huffman = new HuffTree(node);

    

    cout << huffman << endl;

    // delete &huffman;

    // cout << huffman << endl;
}