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

    string lineString;
    string fileString;
    string uniqueString;

    
    ifstream fin;
    fin.open("words.txt");

    while(!fin.eof()){
        fin >> lineString;
        fileString.append(lineString);
    }
    int numOfOcc;
    

    for(int i = 0; i < fileString.length(); i++){
        int countChar = 0;
        for(int j = 0; j < fileString.length(); j++){
            if (fileString[j] == fileString[i]){
                ++ countChar;
            }
        }

        numOfOcc = count(uniqueString.begin(), uniqueString.end(), fileString[i]);

        if (numOfOcc == 0){
            uniqueString.append(string(1,fileString[i]));
            node = new Node(new DataClass(fileString[i], countChar));

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