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

    char letterArr[26];
    int freqOfLetter[26];

    for(int i = 0; i < fileString.length(); i++){

        char *letterCheck = find(begin(nodeExists), end(nodeExists), fileString[i]);

        if (letterCheck == end(nodeExists)) {
            size_t counter = count(fileString.begin(), fileString.end(), fileString[i]);
            nodeExists[ne_idx] = fileString[i];
            letterArr[ne_idx] = fileString[i];
            freqOfLetter[ne_idx] = counter;
            ne_idx += 1;
            
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

    cout << "letters";
    copy(begin(letterArr), end(letterArr), ostream_iterator<char>(cout,"\n"));
    cout << "freq";
    copy(begin(freqOfLetter), end(freqOfLetter), ostream_iterator<int>(cout,"\n"));


    root = node;

    cout << root << endl;

    delete root;
    root = NULL;
    cout << root << endl;

}
