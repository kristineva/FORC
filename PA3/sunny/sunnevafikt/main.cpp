#include <iostream>

#include <fstream>

#include "trees.h"

#include <queue>

#include <string.h>

using namespace std;


int main(){

    priority_queue<DataClass, vector<DataClass>, greater<DataClass> > data_queue;
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

    fin.close();
    
    for(int i = 0; i < fileString.length(); i++){
        checkChar = count(uniqueString.begin(), uniqueString.end(), fileString[i]);

        if (checkChar == 0){
            countChar = count(fileString.begin(), fileString.end(), fileString[i]);
            uniqueString.append(string(1,fileString[i]));
            data = DataClass(countChar, fileString[i]);
            
            data_queue.push(data);
            
        }
    }
    


    // while (!node_queue.empty() ) {
    //     cout << node_queue.top() << "\n";

    //     node_queue.pop();

    // }

    while(!data_queue.empty()){
        Node left = Node(data_queue.top());
        data_queue.pop();
        Node right = Node(data_queue.top());
        data_queue.pop();

        countChar = left.data.number + right.data.number;

        node = Node(DataClass(countChar), &left, &right);

        delete &left;
        delete &right;
    }



    HuffTree huffman;
    huffman = HuffTree(node);

    

    cout <<huffman << endl;

    delete &huffman;

    // cout << huffman << endl;
}