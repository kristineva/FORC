#include <iostream>

#include <fstream>

#include "trees.h"

#include <deque>

#include <string.h>

using namespace std;

int main(){

    Node *root = NULL;
    deque<Node *> node_queue;

    Node *node = NULL;

    string stringOfFile;
    
    ifstream fin;
    fin.open("words.txt");

    while(!fin.eof()){
        fin >> stringOfFile;
    

        cout << stringOfFile;

        for(int i = 0; i < stringOfFile.length(); i++){
            node = new Node(new DataClass(stringOfFile[i]));

            node_queue.push_back(node);
    }
    }

    while(!node_queue.empty()){
        Node *left = node_queue.front();
        node_queue.pop_front();
        Node *right = node_queue.front();
        node_queue.pop_front();
        node = new Node(NULL, left, right);
        if(!node_queue.empty()){
            node_queue.push_back(node);
        }
    }
    

    root = node;

    
    

    cout << root << endl;

    delete root;
    root = NULL;

    cout << root << endl;
}