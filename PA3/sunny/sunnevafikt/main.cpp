#include <iostream>

#include <fstream>

#include "trees.h"

#include <queue>

#include <string.h>

using namespace std;


int main(){

    Node *root = NULL;
    priority_queue<DataClass, vector<DataClass>, greater<DataClass> > node_queue;
    Node node;
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
    
    for(int i = 0; i < fileString.length(); i++){
        checkChar = count(uniqueString.begin(), uniqueString.end(), fileString[i]);

        if (checkChar == 0){
            countChar = count(fileString.begin(), fileString.end(), fileString[i]);
            uniqueString.append(string(1,fileString[i]));
            data = DataClass(countChar, fileString[i]);
            
            
            node_queue.push(data);
            
        }
    }
    

    while (!node_queue.empty() ) {
        cout << node_queue.top() << "\n";

        node_queue.pop();

    }

    while(!node_queue.empty()){
        Node left = Node(node_queue.top());
        node_queue.pop();
        Node right = Node(node_queue.top());
        node_queue.pop();

        countChar = left.data.number + right.data.number;
        node = Node(DataClass(countChar, ' '), &left, &right);
    }

    HuffTree *huffman = NULL;
    huffman = new HuffTree(node);

    fin.close();

    // cout << huffman << endl;

    // delete huffman;
    // huffman = NULL;

    // cout << huffman << endl;
}