#include <iostream>

#include <fstream>

#include "trees.h"

#include <queue>

#include <string.h>

#include <unordered_map>

using namespace std;


int main(){
    Node *node = NULL;
    priority_queue<Node*, vector<Node*>, CompareNodes> node_queue;
    HuffTree *tree = NULL;

    string lineString;
    string fileString;
    string uniqueString;


    int countChar;
    int checkChar;
    
    unordered_map<char, string> huffCode;

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
            node_queue.push(tree->newNode(fileString[i], countChar, NULL, NULL));
        }
    }
    
    while(node_queue.size() > 1){
        Node *left = node_queue.top();
        node_queue.pop();
        Node *right = node_queue.top();
        node_queue.pop();

        countChar = left->number + right->number;
        node_queue.push(tree->newNode('\0', countChar, left, right));
    }

    tree->root = node_queue.top();
    
    tree->huffmanEncoding(tree->root, "", huffCode);

    

    ofstream fout;
    fout.open("encodedWords.txt", ios_base::app);


    for (int i = 0; i < fileString.size(); i++){
        fout << huffCode[fileString[i]];
    }
    // delete &huffman;

    // cout << huffman << endl;
}