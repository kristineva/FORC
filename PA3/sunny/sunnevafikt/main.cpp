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

    int countChar;
    int numOfOcc;
    
    ifstream fin;
    fin.open("words.txt");

    while(!fin.eof()){
        fin >> lineString;
        fileString.append(lineString);
    }
    

    for(int i = 0; i < fileString.length(); i++){
        countChar = count(fileString.begin(), fileString.end(), fileString[i]);
        numOfOcc = count(uniqueString.begin(), uniqueString.end(), fileString[i]);

        if (numOfOcc == 0){
            uniqueString.append(string(1,fileString[i]));
            node = new Node(new DataClass(fileString[i], countChar));

            node_queue.push_back(node);
        }
    }

    // for(int i = 0; i < sizeof(node_queue); i++){
    //     cout << i << ":" << node_queue[i] << endl;
    // }

    std::sort(node_queue.begin(), node_queue.end());
    
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