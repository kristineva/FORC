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

    cout << "AFTER OPEN FILE" << endl;
    

    for(int i = 0; i < fileString.length(); i++){

        checkChar = count(uniqueString.begin(), uniqueString.end(), fileString[i]);

        if (checkChar == 0){
            countChar = count(fileString.begin(), fileString.end(), fileString[i]);
            uniqueString.append(string(1,fileString[i]));
            node_queue.push(new Node(fileString[i], countChar, NULL, NULL));
        }
    }
    
    cout << "AFTER FIRST FOR LOOP" << endl;

    while(node_queue.size() > 1){
        Node *left = node_queue.top();
        node_queue.pop();
        Node *right = node_queue.top();
        node_queue.pop();

        countChar = left->number + right->number;
        node_queue.push(new Node('\0', countChar, left, right));
    }

    cout << "AFTER MAKE TREE WHILE LOOP" << endl;

    HuffTree *tree = new HuffTree(node_queue.top());

    cout << "AFTER MAKing ROOT TOP" << endl;
    
    tree->huffmanEncoding(tree->root, "", huffCode);

    cout << "AFTER huffMAnENDODING" << endl;

    ofstream fout;
    fout.open("encodedWords.txt", ios_base::app);

    for (int i = 0; i < uniqueString.size(); i++){
        fout << uniqueString[i] << " | " << huffCode[uniqueString[i]] << "\n";
    }
    for (int i = 0; i < fileString.size(); i++){
        fout << huffCode[fileString[i]];
    }
    // delete &huffman;

    // cout << huffman << endl;
}