#include <iostream>

#include <fstream>

#include "trees.h"

#include <queue>

#include <string.h>

using namespace std;


int main(){

    Node *root = NULL;
    priority_queue<Node *, vector <Node *>, greater<Node *> > node_queue;
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
    
    // sort(fileString.begin(), fileString.end());

    for(int i = 0; i < fileString.length(); i++){
        countChar = count(fileString.begin(), fileString.end(), fileString[i]);
        numOfOcc = count(uniqueString.begin(), uniqueString.end(), fileString[i]);

        if (numOfOcc == 0){
            uniqueString.append(string(1,fileString[i]));
            node = new Node(new DataClass(fileString[i], countChar));

            node_queue.push(node);
        }
    }

    cout << node_queue.top() << endl;
    
    while(!node_queue.empty()){
        Node *left = node_queue.top();
        node_queue.pop();
        Node *right = node_queue.top();
        node_queue.pop();

        numOfOcc = left->data->number + right->data->number;
        node = new Node(new DataClass(' ', numOfOcc), left, right);
        if(!node_queue.empty()){
            node_queue.push(node);
        }
    }

    HuffTree *huffman = NULL;
    huffman = new HuffTree(node);


    
    
    cout << huffman << endl;

    delete huffman;
    huffman = NULL;

    cout << huffman << endl;
}