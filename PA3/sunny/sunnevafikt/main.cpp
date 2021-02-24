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
    string noDuplString;
    
    ifstream fin;
    fin.open("words.txt");

    while(!fin.eof()){
        fin >> stringOfFile;
        
        int numOfOcc;
        int countChar = 0;

        for(int i = 0; i < stringOfFile.length(); i++){
            for(int j = 0; j < stringOfFile.length(); j++){
                if (stringOfFile[j] == stringOfFile[i]){
                    ++ countChar;
                }
            }

            numOfOcc = count(noDuplString.begin(), noDuplString.end(), stringOfFile[i]);

            if (numOfOcc == 0){
                noDuplString.append(string(1,stringOfFile[i]));
                node = new Node(new DataClass(stringOfFile[i], countChar));

                node_queue.push_back(node);
            }
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