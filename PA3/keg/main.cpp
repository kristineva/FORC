#include <iostream>
#include <fstream>
#include <deque>
#include <string.h>
#include <algorithm>
#include "trees.h"

using namespace std;


int main(){

    Node *root = NULL;
    deque<Node *> node_queue;
    Node *node = NULL;

    string fileString;
    string stringOfLine;

    ifstream fin;
    fin.open("words.txt");

    while(!fin.eof()){
        fin >> stringOfLine;
        fileString.append(stringOfLine);
    }

    
    char nodeExists[26];
    int ne_idx = 0;
    
    for(int i = 0; i < fileString.length(); i++){

        char *letterCheck = find(begin(nodeExists), end(nodeExists), fileString[i]);

        if (letterCheck == end(nodeExists)) {
            nodeExists[ne_idx] = fileString[i];
            ne_idx += 1;
            size_t counter = count(fileString.begin(), fileString.end(), fileString[i]);
            node = new Node(new DataClass(fileString[i], counter));
            node_queue.push_back(node);
        }
    }

    while(!node_queue.empty()) {
        Node *left = node_queue.front();
        node_queue.pop_front();
        Node *right = node_queue.front();
        node_queue.pop_front();
        node = new Node(NULL, left, right);
        if(!node_queue.empty()) {
            node_queue.push_back(node);
        }
        
    }

    root = node;

    cout << root << endl;

    delete root;
    root = NULL;
    cout << root << endl;

}
